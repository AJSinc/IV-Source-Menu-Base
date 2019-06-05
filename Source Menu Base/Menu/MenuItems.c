/**
 *	Item types for the Menu Setup
 *	If adding any more types be sure to add them to
 *	the Menu GUI if they need to any special display, otherwise Item Type 1 should do fine.
 */

#include "Menu.h"

//	Adds a basic item that checks if the current item isn't skipped
//	Returns false if the item is to be skipped, or the menu.itemCount has already reached it's max
bool AddItem(char* aName)
{
	if(menu.skippedItemCounter > 0)
	{
		menu.skippedItemCounter--;
		return false;
	}
	if(menu.itemCount == MAX_MENU_ITEMS)
	{
		menu.remainingItemCount++;
		return false;
	}
	menuItem[menu.itemCount].itemName = aName;
	return true;
}

//	Adds a sub menu that can be linked to in the menuSetup
void AddSubMenu(char* aName)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = SUBMENU_ITEM;
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions
void AddFunction(char* aName)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = FUNCTION_ITEM;
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions, but has a value that can be linked to in the menuFunctions
void AddValue(char* aName, int aValue)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = FUNCTION_ITEM;
	menuItem[menu.itemCount].value = aValue;
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions, but has a float value that can be linked to in the menuFunctions
void AddFloatValue(char* aName, float aFloat)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = FUNCTION_ITEM;
	menuItem[menu.itemCount].floatValue = aFloat;
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions, but has a string value that can be linked to in the menuFunctions
void AddStringValue(char* aName, char* aString)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = FUNCTION_ITEM;
	menuItem[menu.itemCount].charValue = aString;
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions, but has a value that can be linked to in the menuFunctions
//	Also will show an integer on the side of the menu.
void AddIntHelper(char* aName, int aStartValue, int aMaxValue, int aMinValue)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = INT_ITEM;
	menuItem[menu.itemCount].maxValue = aMaxValue;
	menuItem[menu.itemCount].floatMaxValue = (float) aMinValue;
	if(GetSetupValue())
	{
		menuItem[menu.itemCount].value = aStartValue;
	}
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions, but has a float value that can be linked to in the menuFunctions
//	Also will show an floating point number on the side of the menu.
void AddFloatHelper(char* aName, float aStartValue, float aMaxValue, float aMinValue)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = FLOAT_ITEM;
	menuItem[menu.itemCount].floatMaxValue = aMaxValue;
	menuItem[menu.itemCount].maxValue = (int) aMinValue;
	if(GetSetupValue())
	{
		menuItem[menu.itemCount].floatValue = aStartValue;
	}
	menu.itemCount++;
}

//	Adds an item that can do a function in the menuFunctions (mainly for turning true/false), but has a boolean that can be linked to in the menuFunctions
//	Also will show whether the value is true/false on the side of the menu.
void AddBool(char* aName, bool aBoolValue)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = BOOL_ITEM;
	menuItem[menu.itemCount].value = aBoolValue;
	menu.itemCount++;
}

// Adds an item that can do a function in the menuFunctions, but has a string value that can be linked to it in the menuFunctions.
// Also will show a string on the side of the menu. Accepts a string array as a parameter.
//helper function
void AddStringHelper2(char* aName, char* aStringValue, int aMaxValue)
{
	menuItem[menu.itemCount].type = STRING_ITEM;
	menuItem[menu.itemCount].maxValue = aMaxValue;
	menuItem[menu.itemCount].charValue = aStringValue;
	menu.itemCount++;
}


// Adds an item that does nothing in the menu, use to show if there is an error in the setup/menu.
void AddError(char* aName)
{
	if(!AddItem(aName)) return;
	menuItem[menu.itemCount].type = INVALID_ITEM;
	menu.itemCount++;
}

// Sets the item info for the previous item in the setup
void SetItemInfoHelper(char* itemInfo)
{
	if(menu.itemCount > 0 && menu.remainingItemCount == 0)
	{
		menuItem[menu.itemCount - 1].itemInfo = itemInfo;
	}
}

// Sets the item info for the item at a certain index
void SetItemInfoIndexHelper(char* itemInfo, int itemIndex)
{
	if(ItemIsBeingDisplayed(itemIndex))
	{
		menuItem[GetDisplayIndexOfItem(itemIndex)].itemInfo = itemInfo;
	}
}

//Check if items at a certain index are actually being displayed
bool ItemIsBeingDisplayed(int itemIndex)
{
	return itemIndex > menu.skippedItemCount && itemIndex <= (menu.skippedItemCount + MAX_MENU_ITEMS);
}

//Check if items in a range actually being displayed
//Inclusive range
bool ItemsInRangeBeingDisplayed(int itemIndexStart, int itemIndexEnd)
{
	return itemIndexStart > menu.skippedItemCount && itemIndexEnd <= (menu.skippedItemCount + MAX_MENU_ITEMS);
}


