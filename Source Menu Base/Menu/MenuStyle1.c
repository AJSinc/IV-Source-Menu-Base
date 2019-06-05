/**
 *	Menu Style
 *
 *	by: Buffeting
 */
 
#include "Menu.h"

void MenuStyleActivate(){}
void MenuStyleDeactivate(){}
void MenuStyleConfirmFunction(){}
void MenuStyleConfirmSubMenu(){}
void MenuStyleBackSubMenu(){}
void MenuStylePreviousItem(){}
void MenuStyleNextItem(){}
void MenuStyleChangeInt(){}
void MenuStyleChangeFloat(){}
void MenuStyleChangeString(){}

void MenuDisplay()
{
	
	//float itemPosX = TEXT_POS_X;
	float itemPosY = TEXT_POS_Y;
	
	//black box
	DrawCurvedWindow(CURVED_WINDOW_POS_X, CURVED_WINDOW_POS_Y, CURVED_WINDOW_SIZE_X, (CURVED_WINDOW_SIZE_Y + CURVED_WINDOW_SIZE_Y_MULT * menu.itemCount), CURVED_WINDOW_ALPHA);
	
	SetUpDraw(HEADER_TEXT_TYPE, HEADER_TEXT_SIZE_X, HEADER_TEXT_SIZE_Y, HEADER_R, HEADER_G, HEADER_B, HEADER_ALPHA);
	DrawText("STRING", HEADER_POS_X , HEADER_POS_Y, menu.header);
	
	for(int i = 0; i < menu.itemCount; i++)
	{
		
		if(menu.highlightedItem == i)
		{//selected item text
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			//
		}
		else
		{//non-selected item text
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
			//
		}
		DrawText("STRING", TEXT_POS_X, itemPosY, menuItem[i].itemName);

		//special items
		if(menuItem[i].type == INT_ITEM)
		{//ints
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);				
			DrawInt("NUMBR", INT_NUM_POS_X, itemPosY, menuItem[i].value);
		}
		else if(menuItem[i].type == FLOAT_ITEM)
		{//floats
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);				
			DrawFloat("NUMBR", FLOAT_NUM_POS_X, itemPosY, menuItem[i].floatValue, 1);
		}
		else if(menuItem[i].type == BOOL_ITEM)
		{//bools
			if(menuItem[i].value)
			{//bool true
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
				DrawText("STRING", BOOL_POS_X, itemPosY, BOOL_TRUE_TEXT);
			}
			else
			{//bool false
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
				DrawText("STRING", BOOL_POS_X, itemPosY, BOOL_FALSE_TEXT);
			}
		}
		else if(menuItem[i].type == STRING_ITEM)
		{//strings
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			DrawTextGetWidth("STRING", STRING_POS_X, itemPosY, menuItem[i].charValue);
		}
	
		//itemPosX += TEXT_SPACING_X;
		itemPosY += TEXT_SPACING_Y;	//makes every item shift lower than the previous item
	}
	
	//arrows
	if(menu.skippedItemCount > 0)
	{//arrow up
		SetUpDraw(TEXT_TYPE, ARROW_SIZE, ARROW_SIZE, 0, 0, 0, 255);
		DrawText("STRING", ARROW_UP_LOCATION_X , ARROW_UP_LOCATION_Y, ARROW_UP);
	}
	if(menu.remainingItemCount > 0)
	{//down
		SetUpDraw(TEXT_TYPE, ARROW_SIZE, ARROW_SIZE, 0, 0, 0, 255);
		DrawText("STRING", ARROW_DOWN_LOCATION_X , ARROW_DOWN_LOCATION_Y, ARROW_DOWN);
	}

}


