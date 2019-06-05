/**
 *	
 *  
 *
 */

#include "Menu.h"

menuItemStructure menuItem[MAX_MENU_ITEMS];

menuStructure menu;

#pragma region Menu //{

void SetMenuFlag(uint Flag, bool status)
{
	SetBit(menu.status, Flag, status);
}

bool GetMenuFlag(uint Flag)
{
	return GetBit(menu.status, Flag);
}

void ResetMenuFlags()
{
	menu.status = 0;
}

void ToggleHelper(int *x)
{
	*x = !*x;
	menuItem[menu.highlightedItem].value = *x;
	bool tmp = GetMenuFlag(DISABLE_GET_SETUP_VALUES);
	SetMenuFlag(DISABLE_GET_SETUP_VALUES, true);
	ReloadSetup();
	SetMenuFlag(DISABLE_GET_SETUP_VALUES, tmp);
}

void ActivateMenu()
{
	if(GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("menu_startup") != 0) return;	//a menu is already being displayed
	REQUEST_SCRIPT("menu_startup");
	MenuStyleActivate();
	SetMenuFlag(MENU_ENABLED, true);
	menu.scrollTicksPassed = 0;
	menu.activateInputHeld = true;
	
	CLEAR_PRINTS();
	CLEAR_HELP();
	
	SET_CINEMATIC_BUTTON_ENABLED(false);
	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), true);
	
	uint menuThreadID = GET_ID_OF_THIS_THREAD();
	while(!HAS_SCRIPT_LOADED("menu_startup")) WAIT(0);
	START_NEW_SCRIPT_WITH_ARGS("menu_startup", &menuThreadID, 1, 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("menu_startup");
	CREATE_MOBILE_PHONE(2);
	ReloadSetup();
}

void DeactivateMenu()
{
	MenuStyleDeactivate();
	SetMenuFlag(MENU_ENABLED, false);
	menu.activateInputHeld = false;
	
	char * cellphone = IS_NETWORK_SESSION() ? "mpcellphone" : "spcellphone";
	REQUEST_SCRIPT(cellphone);
	
	CLEAR_PRINTS();
	CLEAR_HELP();
	
	SET_CINEMATIC_BUTTON_ENABLED(true);
	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), false);
	
	DESTROY_MOBILE_PHONE();
	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("menu_startup");

	while(!HAS_SCRIPT_LOADED(cellphone)) WAIT(0);
	START_NEW_SCRIPT(cellphone, 1024);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED(cellphone);
}

void ResetMenu()
{
	//Menu struct
	for(int i = 0; i < MAX_MENU_ITEMS; i++)
	{
		menuItem[i].itemName = "";
		menuItem[i].type = INVALID_ITEM;
		menuItem[i].itemInfo = "";
		menuItem[i].value = 0;
		menuItem[i].maxValue = 0;
		menuItem[i].floatValue = 0.0;
		menuItem[i].floatMaxValue = 0.0;
		menuItem[i].charValue = "";
	}
	
	menu.header = "";
	ResetMenuFlags();
	menu.level = 0;
	menu.itemCount = 0;
	menu.remainingItemCount = 0;
	menu.skippedItemCount = 0;
	menu.skippedItemCounter = 0;
	menu.scrollTicksPassed = 0;
	menu.highlightedItem = 0;
	for(int i = 0; i < MAX_MENU_LEVELS; i++)
		menu.lastSelected[i] = 0;
	menu.menuRed = START_RED;
	menu.menuGreen = START_GREEN;
	menu.menuBlue = START_BLUE;
	MenuSetup();
}

void ResetMenuItems()
{
	for(int i = 0; i < menu.itemCount; i++)
	{
		menuItem[i].type = INVALID_ITEM;
		menuItem[i].itemInfo = "";
	}
}

void ReloadSetup()
{
	ResetMenuItems();
	MenuSetup();
}

void InitMenuSetup()
{
	menu.itemCount = 0;
	menu.remainingItemCount = 0;
	menu.skippedItemCounter = menu.skippedItemCount;
}

void AdvancedToMenuLevel(int level)
{
	if(menu.level >= level || level < 0 || level > MAX_MENU_LEVELS) return;
	
	while(menu.level < level)
	{
		ResetMenuItems();
		menu.lastSelected[menu.level] = menu.highlightedItem + menu.skippedItemCount + 1;
		menu.level++;
		menu.skippedItemCount = 0;
		menu.highlightedItem = 0;
	}
	MenuSetup();
}

void ReturnToMenuLevel(int level)
{
	if(menu.level <= level || level < 0 || level >= MAX_MENU_LEVELS) return;
	
	ResetMenuItems();
		
	menu.level = level;
	menu.skippedItemCount = 0;
	menu.highlightedItem = menu.lastSelected[menu.level] - 1;
	if(menu.lastSelected[menu.level] >= MAX_MENU_ITEMS)
	{
		menu.skippedItemCount = menu.lastSelected[menu.level] - MAX_MENU_ITEMS;
		menu.highlightedItem = MAX_MENU_ITEMS - 1;
	}
	MenuSetup();
}

#pragma endregion //}

#pragma region Display //{

void SetUpDraw(int type, float width, float height, int r, uint g, int b, int a)
{
	SET_TEXT_FONT(0);

	SET_TEXT_BACKGROUND(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	SET_TEXT_EDGE(0, 0, 0, 0, 255);

	switch(type)
	{
		case 1:
			SET_TEXT_BACKGROUND(1);
			break;
		case 2:
			SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
			break;
		case 3:
			SET_TEXT_EDGE(1, 0, 0, 0, 255);
			break;
		case 4:
			SET_TEXT_EDGE(1, 235, 235, 235, 255);
			break;
	}

	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_SCALE(width, height);
	SET_TEXT_USE_UNDERSCORE(1);
	SET_TEXT_PROPORTIONAL(1);
	
	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(0);
	SET_TEXT_RIGHT_JUSTIFY(0);
}

float DrawTextGetWidth(char *gxtName, float x, float y, char *val)
{
	float width = GET_STRING_WIDTH_WITH_STRING(gxtName, val);
	DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, gxtName, val);
	return width;
}

#pragma endregion //}

#pragma region Input //{

bool IsScrollingWaitTimeDone()
{
	if (menu.scrollTick <= GetTickCount() || menu.scrollTicksPassed <= 0)
	{
		menu.scrollTicksPassed++;
		menu.scrollTick = (menu.scrollTicksPassed > MENU_SCROLL_FAST_HOLD_COUNT) ? MENU_SCROLL_FAST_WAIT_TIME : MENU_SCROLL_WAIT_TIME;
		menu.scrollTick += GetTickCount();
		return true;
	}
	return false;
}

bool IsActivateMenuInputHeld()
{
	//return ((IsGamepadButtonPressed(OPEN_MENU_BUTTON_HOLD) && IsGamepadButtonPressed(OPEN_MENU_BUTTON_PRESS)) || (IsKeyboardKeyPressed(KB_OPEN_MENU_KEY)))
	if(menu.activateInputHeld)
	{
		if((IsGamepadButtonPressed(OPEN_MENU_BUTTON_HOLD) || IsGamepadButtonPressed(OPEN_MENU_BUTTON_PRESS)) || IsKeyboardKeyPressed(KB_OPEN_MENU_KEY))
			return true;
		menu.activateInputHeld = false;
	}
	return false;
}

void MenuInput()
{
	if (IS_PAUSE_MENU_ACTIVE()) return;
	if (IsActivateMenuInputHeld()) return;
	
	HIDE_HELP_TEXT_THIS_FRAME();
	SET_CINEMATIC_BUTTON_ENABLED(false);
	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), true);
	//button inputs
	if (IsActivateMenuInput())
	{
		DeactivateMenu();
		return;
	}
	else if (IsButtonJustPressed(BUTTON_BACK, KB_BUTTON_BACK))
	{
		if (menu.level > 0)
		{
			MenuStyleBackSubMenu();
			ReturnToLastMenuLevel();
		}
		else DeactivateMenu();
	}
	else if (menu.itemCount == 0)
	{//Check if the menu is empty
		return;
	}
	else if (IsButtonJustPressed(BUTTON_CONFIRM, KB_BUTTON_CONFIRM))
	{
		if (menuItem[menu.highlightedItem].type)
		{//menu function
			if (menuItem[menu.highlightedItem].type != INVALID_ITEM)
			{
				if (!GetMenuFlag(DISABLE_MENU_FUNCTIONS))
				{
					MenuStyleConfirmFunction();
					MenuFunctions();
				}
			}
		}
		else
		{//sub menu
			MenuStyleConfirmSubMenu();
			AdvanceToNextMenulevel();
		}
	}
	else if (IsButtonPressed(BUTTON_UP, KB_BUTTON_UP))
	{
		if (IsScrollingWaitTimeDone())
		{
			MenuStylePreviousItem();
			menu.highlightedItem--;
			if (menu.highlightedItem < 0)
			{
				menu.highlightedItem = menu.itemCount - 1;
				if (menu.skippedItemCount > 0)
				{//Scrolling back up the list if some items were skipped
					menu.highlightedItem = 0;
					menu.skippedItemCount--;
					//could add code here to keep some values the same

					bool tmp = GetMenuFlag(DISABLE_GET_SETUP_VALUES);
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, true);
					for (int i = (MAX_MENU_ITEMS - 1); i > 0; i--)
					{
						menuItem[i].value = menuItem[i - 1].value;
						menuItem[i].floatValue = menuItem[i - 1].floatValue;
						menuItem[i].charValue = menuItem[i - 1].charValue;
					}

					ReloadSetup();
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, tmp);
				}
				else if (menu.remainingItemCount > 0)
				{//If there are remaining items in the list it will go to the bottom of the list
					menu.skippedItemCount = menu.remainingItemCount;
					ReloadSetup();
				}
			}
		}
	}
	else if (IsButtonPressed(BUTTON_DOWN, KB_BUTTON_DOWN))
	{
		if (IsScrollingWaitTimeDone())
		{
			MenuStyleNextItem();
			menu.highlightedItem++;
			if (menu.highlightedItem >= menu.itemCount)
			{
				menu.highlightedItem = 0;
				if (menu.remainingItemCount > 0)
				{//Scrolling down the item list if there are still remaining items
					menu.highlightedItem = MAX_MENU_ITEMS - 1;
					menu.skippedItemCount++;
					//could add code here to keep some values the same

					bool tmp = GetMenuFlag(DISABLE_GET_SETUP_VALUES);
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, true);
					for (int i = 0; i < (MAX_MENU_ITEMS - 1); i++)
					{
						menuItem[i].value = menuItem[i + 1].value;
						menuItem[i].floatValue = menuItem[i + 1].floatValue;
						menuItem[i].charValue = menuItem[i + 1].charValue;
					}

					ReloadSetup();
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, tmp);
				}
				else if (menu.skippedItemCount > 0)
				{//Back to the top of the item list once reaching the bottom & there were skipped items
					menu.skippedItemCount = 0;
					ReloadSetup();
				}
			}
		}
	}
	else if (IsButtonPressed(BUTTON_LEFT, KB_BUTTON_LEFT))
	{
		if (IsScrollingWaitTimeDone())
		{
			switch(menuItem[menu.highlightedItem].type)
			{
				float fMin;
				int min;
				case INT_ITEM:
					MenuStyleChangeInt();
					min = (int)menuItem[menu.highlightedItem].floatMaxValue;
					menuItem[menu.highlightedItem].value -= 1;
					if (menuItem[menu.highlightedItem].value < min)
						menuItem[menu.highlightedItem].value = menuItem[menu.highlightedItem].maxValue;
					break;
				case FLOAT_ITEM:
					MenuStyleChangeFloat();
					fMin = (float)menuItem[menu.highlightedItem].maxValue;
					menuItem[menu.highlightedItem].floatValue -= 0.10000000f;
					if (fMin - menuItem[menu.highlightedItem].floatValue > 0.01000000f)
						menuItem[menu.highlightedItem].floatValue = menuItem[menu.highlightedItem].floatMaxValue;
					else if (menuItem[menu.highlightedItem].floatValue < 0.01000000f && menuItem[menu.highlightedItem].floatValue > -0.09000000f)
						menuItem[menu.highlightedItem].floatValue = 0.00000000f;
					break;
				case STRING_ITEM:
					MenuStyleChangeString();
					bool tmp = GetMenuFlag(DISABLE_GET_SETUP_VALUES);
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, true);
					menuItem[menu.highlightedItem].value -= 1;
					if (menuItem[menu.highlightedItem].value < 0)
						menuItem[menu.highlightedItem].value = menuItem[menu.highlightedItem].maxValue - 1;
					ReloadSetup();
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, tmp);
					break;
			}
		}
	}
	else if (IsButtonPressed(BUTTON_RIGHT, KB_BUTTON_RIGHT))
	{
		if (IsScrollingWaitTimeDone())
		{
			
			switch(menuItem[menu.highlightedItem].type)
			{
				float fMin;
				int min;
				case INT_ITEM:
					MenuStyleChangeInt();
					min = (int)menuItem[menu.highlightedItem].floatMaxValue;
					menuItem[menu.highlightedItem].value += 1;
					if (menuItem[menu.highlightedItem].value > menuItem[menu.highlightedItem].maxValue)
						menuItem[menu.highlightedItem].value = min;
					break;
				case FLOAT_ITEM:
					MenuStyleChangeFloat();
					fMin = (float)menuItem[menu.highlightedItem].maxValue;
					menuItem[menu.highlightedItem].floatValue += 0.10000000f;
					if (menuItem[menu.highlightedItem].floatMaxValue - menuItem[menu.highlightedItem].floatValue < -0.01000000f)
						menuItem[menu.highlightedItem].floatValue = fMin;
					break;
				case STRING_ITEM:
					MenuStyleChangeString();
					bool tmp = GetMenuFlag(DISABLE_GET_SETUP_VALUES);
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, true);
					menuItem[menu.highlightedItem].value += 1;
					if (menuItem[menu.highlightedItem].value >= menuItem[menu.highlightedItem].maxValue)
						menuItem[menu.highlightedItem].value = 0;
					ReloadSetup();
					SetMenuFlag(DISABLE_GET_SETUP_VALUES, tmp);
					break;
			}
		}
	}
	else
	{
		menu.scrollTicksPassed = 0;
	}
	//menu.highlightedItem safety
	if (menu.highlightedItem >= menu.itemCount) /*|| menu.highlightedItem >= MAX_MENU_ITEMS )*/
		menu.highlightedItem = menu.itemCount - 1;
	if (menu.highlightedItem < 0)
		menu.highlightedItem = 0;
}

#pragma endregion //}
