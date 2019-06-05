/**
 *	
 *  
 *
 */

#pragma once

#include "types.h"
#include "constants.h"
#include "../Consts.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"
#include "varargs.h"

#include "GTAIV/commonIV.h"


#define MENU_STYLE_INCLUDE2(x) stringify(MenuStyle ## x.h )	//macro becomes it's value, and is stringified as it's number value
#define MENU_STYLE_INCLUDE(x) MENU_STYLE_INCLUDE2(x)	//pass in macro

#include MENU_STYLE_INCLUDE(MENU_STYLE)

#pragma region Menu //{

enum MenuFlags
{
	MENU_ENABLED = 0,
	DISABLE_INPUT,
	DISABLE_MENU_FUNCTIONS,
	DISABLE_GET_SETUP_VALUES,
	DISABLE_DISPLAY,
	DISABLE_LOOPED_FUNCTIONS,
	DISABLE_LOOPED_NETWORK,
	DISABLE_LOOPED_SETUP,
	USE_LOOPED_SETUP_AS_SETUP,
	DISABLE_CURRENT_SPECIAL_DRAW_ITEM,
	DISABLE_ALL_SPECIAL_DRAW_ITEMS,
};

typedef struct menuItemStructure
{
	char* itemName;
	int type;
	char* itemInfo;

	int value;
	int maxValue;
	float floatValue;
	float floatMaxValue;
	char* charValue;

} menuItemStructure;

typedef struct menuStructure
{
	char* header;

	int status;
	int level;
	int itemCount;
	int remainingItemCount;
	int skippedItemCount;
	int skippedItemCounter;
	uint scrollTick;
	uint scrollTicksPassed;
	bool activateInputHeld;
	int highlightedItem;
	int lastSelected[MAX_MENU_LEVELS];
	//menu colors
	int menuRed;
	int menuGreen;
	int menuBlue;

} menuStructure;

extern menuItemStructure menuItem[MAX_MENU_ITEMS];

extern menuStructure menu;

//Functions
void SetMenuFlag(uint Flag, bool status);
bool GetMenuFlag(uint Flag);
void ResetMenuFlags();
void InitMenu();
void ActivateMenu();
void DeactivateMenu();
void ResetMenu();
void ResetMenuItems();
void MenuFunctions();
void LoopedFunctions();
void LoopedNetworkFunctions();
void MenuSetup();
void ReloadSetup();
void InitMenuSetup();
void LoopedSetup();
void ToggleHelper(int *x);
#define Toggle(x) ToggleHelper(&x)	//macro to set booleans true/false
void AdvancedToMenuLevel(int level);
void ReturnToMenuLevel(int level);
#define InMenuLevel(l) (menu.level == l)
#define AdvanceToNextMenulevel() AdvancedToMenuLevel(menu.level + 1)
#define ReturnToLastMenuLevel() ReturnToMenuLevel(menu.level - 1)
#define LastSelectedAtLevel(level, item) menu.lastSelected[level] == item
#define LastSelectedAtLevelInRange(level, item, item2) menu.lastSelected[level] >= item && menu.lastSelected[level] <= item2

#define SelectedItem(x) selectedItem == x
#define InitSelectedItem() int selectedItem = GetSelectedItemIndex();

#pragma endregion //}

#pragma region Menu Items //{

enum ItemTypes
{
	INVALID_ITEM = -1,
	SUBMENU_ITEM = 0,
	FUNCTION_ITEM = 1,
	INT_ITEM,
	FLOAT_ITEM,
	BOOL_ITEM,
	STRING_ITEM,
};

void AddSubMenu(char* aName);
void AddFunction(char* aName);
void AddValue(char* aName, int aValue);
void AddFloatValue(char* aName, float aFloat);
void AddStringValue(char* aName, char* aString);
#define GetSetupValue() (!GetMenuFlag(DISABLE_GET_SETUP_VALUES) || ((menu.itemCount == (MAX_MENU_ITEMS - 1)) && IsButtonPressed(BUTTON_DOWN, KB_BUTTON_DOWN)) || (IsButtonPressed(BUTTON_UP, KB_BUTTON_UP) && menu.itemCount == 0))

#define AddInt(...) OVERLOAD(AddInt, __VA_ARGS__)
#define AddInt3(aName, aStartValue, aMaxValue)				AddIntHelper(aName, aStartValue, aMaxValue, 1)
#define AddInt4(aName, aStartValue, aMaxValue, aMinValue)	AddIntHelper(aName, aStartValue, aMaxValue, aMinValue)
void AddIntHelper(char* aName, int aStartValue, int aMaxValue, int aMinValue);
#define AddFloat(...) OVERLOAD(AddFloat, __VA_ARGS__)
#define AddFloat3(aName, aStartValue, aMaxValue)			AddFloatHelper(aName, aStartValue, aMaxValue, 0.0f)
#define AddFloat4(aName, aStartValue, aMaxValue, aMinValue)	AddFloatHelper(aName, aStartValue, aMaxValue, aMinValue)
void AddFloatHelper(char* aName, float aStartValue, float aMaxValue, float aMinValue);
void AddBool(char* aName, bool aBoolValue);
#define AddString(...) OVERLOAD(AddString, __VA_ARGS__)
#define AddString2(x, p)	AddStringHelper(x, p, 0)
#define AddString3(x, p, v)	AddStringHelper(x, p, v)
#define AddStringHelper(x, p, v)\
if(AddItem(x))\
{\
	if(GetSetupValue())\
	{\
		menuItem[menu.itemCount].value = v;\
	}\
	AddStringHelper2(x, p[(menuItem[menu.itemCount].value)], (sizeof(p) / 4));\
}
void AddStringHelper2(char* aName, char* aStringValue, int aMaxValue);
void AddError(char* aName);
#define SetItemInfo(...) OVERLOAD(SetItemInfo, __VA_ARGS__)
#define SetItemInfo1(itemInfo) SetItemInfoHelper(itemInfo)
#define SetItemInfo2(itemInfo, itemIndex) SetItemInfoIndexHelper(itemInfo, itemIndex)
void SetItemInfoHelper(char* itemInfo);
void SetItemInfoIndexHelper(char* itemInfo, int itemIndex);

#define GetSelectedItemIndex()	(menu.highlightedItem + menu.skippedItemCount + 1)
#define GetDisplayIndexOfItem(x) (x - 1 - menu.skippedItemCount)
bool ItemIsBeingDisplayed(int itemIndex);
bool ItemsInRangeBeingDisplayed(int itemIndexStart, int itemIndexEnd);
#define SetItemNameFromBool(aName, aName2, val) val ? aName : aName2
#define SetHeader(str) menu.header = str
#define GetHeader() menu.header

#pragma endregion //}

#pragma region Menu Settings //{

//Loading Settings
bool LoadSettingBool(char* gxtEntry, int index, uint stat, int bitIndex);
byte LoadSettingByte(char* gxtEntry, int index, uint stat, int byteIndex);
int LoadSettingInt(char* gxtEntry, int index, uint stat);
uint LoadGXTSetting(char* gxtEntry, char* gxtStringSetting);
uint LoadGXTCustomSetting(char* gxtEntry, char* gxtStringSetting, char* compareString, uint resultTrue, uint resultFalse);
//Saving Settings
void SaveSettingBool(char* gxtEntry, int index, uint stat, int bitIndex, bool val);
void SaveSettingByte(char* gxtEntry, int index, uint stat, int byteIndex, byte val);
void SaveSettingInt(char* gxtEntry, int index, uint stat, int val);
void SaveMenuSettings();

#pragma endregion //}

#pragma region Input //{

bool IsScrollingWaitTimeDone();
bool IsActivateMenuInputHeld();
void MenuInput();
#define IsButtonPressed(x, y)		(IS_BUTTON_PRESSED(0, x) 	  || IS_GAME_KEYBOARD_KEY_PRESSED(y))
#define IsButtonJustPressed(x, y)	(IS_BUTTON_JUST_PRESSED(0, x) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(y))
#define IsActivateMenuInput() 		((IS_BUTTON_PRESSED(0, OPEN_MENU_BUTTON_HOLD) && IS_BUTTON_JUST_PRESSED(0, OPEN_MENU_BUTTON_PRESS)) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KB_OPEN_MENU_KEY))
#define IsGamepadButtonPressed(x) 		IS_BUTTON_PRESSED(0, x)
#define IsGamepadButtonJustPressed(x) 	IS_BUTTON_JUST_PRESSED(0, x)
#define IsKeyboardKeyPressed(y)			IS_GAME_KEYBOARD_KEY_PRESSED(y)
#define IsKeyboardKeyJustPressed(y)		IS_GAME_KEYBOARD_KEY_JUST_PRESSED(y)

#pragma endregion //}

#pragma region Display //{
void SetUpDraw(int type, float width, float height, int r, uint g, int b, int a);
float DrawTextGetWidth(char *gxtName, float x, float y, char *val);
#define DrawText(gxtName, x, y, val) DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, gxtName, val)
#define DrawInt(gxtName, x, y, val) DISPLAY_TEXT_WITH_NUMBER(x, y, gxtName, val)
#define DrawFloat(gxtName, x, y, val, decimalPlace) DISPLAY_TEXT_WITH_FLOAT(x, y, gxtName, val, decimalPlace)
#define DrawCurvedWindow(x, y, width, height, alpha) DRAW_CURVED_WINDOW(x, y, width, height, alpha)
#define DrawRectangle(x, y, height, width, red, grn, blu, alpha) DRAW_RECT(x, y, height, width, red, grn, blu, alpha)
// x/y coords = top left of rectangle as opposed to direct center
#define DrawRectangle2(x, y, height, width, red, grn, blu, alpha) DRAW_RECT(x + height / 2.0, y + width / 2.0, height, width, red, grn, blu, alpha)

#pragma endregion //}

#pragma region Menu Display //{

void ResetMenuStyleGlobals();
void MenuStyleActivate();
void MenuStyleDeactivate();
void MenuStyleConfirmFunction();
void MenuStyleConfirmSubMenu();
void MenuStyleBackSubMenu();
void MenuStylePreviousItem();
void MenuStyleNextItem();
void MenuStyleChangeInt();
void MenuStyleChangeFloat();
void MenuStyleChangeString();
void MenuDisplay();
void InitMenu();

#pragma endregion //}
