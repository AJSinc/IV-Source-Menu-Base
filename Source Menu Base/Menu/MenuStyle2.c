/**
 *  Menu Style
 *
 *	by: Herr Muskelprotze
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

void DrawTitle(float x, float y, float width, float height, uint r, uint g, uint b, uint a, char *val)
{
#if PLATFORM == PLATFORM_PC
	if (!IS_FONT_LOADED(7))
		LOAD_TEXT_FONT(7);
	SET_TEXT_FONT(7);
#else
	if (!IS_FONT_LOADED(6))
		LOAD_TEXT_FONT(6);
	SET_TEXT_FONT(6);
#endif

	SET_TEXT_BACKGROUND(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	SET_TEXT_EDGE(1, 0, 0, 0, 255);
	
	SET_TEXT_WRAP(0.0000, 1.0000);	

	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_SCALE(width, height);
	SET_TEXT_PROPORTIONAL(1);
	
	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(1);
	SET_TEXT_RIGHT_JUSTIFY(0);
	
	DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, "STRING", val);
}

void MenuDisplay()
{
	//float itemPosX = TEXT_POS_X;
	float itemPosY = TEXT_POS_Y;
		  
	DrawTitle(TITLE_POS_X, TITLE_POS_Y, TITLE_TEXT_SIZE_X, TITLE_TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TITLE_ALPHA, MENU_TITLE);
		
	SetUpDraw(FOOTER_TEXT_TYPE, FOOTER_TEXT_SIZE_X, FOOTER_TEXT_SIZE_Y, FOOTER_R, FOOTER_G, FOOTER_B, FOOTER_ALPHA);
	DrawText("STRING", FOOTER_POS_X , FOOTER_POS_Y, menu.header);
	
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
				// (
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed,menu.menuGreen,menu.menuBlue, TEXT_ALPHA);
				DrawText("STRING", INT_LEFT_PAREN_POS_X, itemPosY, "(");
				// int number
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);				
				DrawInt("NUMBR", INT_NUM_POS_X, itemPosY, menuItem[i].value);
				// )
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
				if(menuItem[i].value < 10)			//1 figure number
					DrawText("STRING", INT_1_RIGHT_PAREN_POS_X, itemPosY, ")");
				else if(menuItem[i].value < 100)	//2 figure number
					DrawText("STRING", INT_2_RIGHT_PAREN_POS_X, itemPosY, ")");
				else							//3 figure number
					DrawText("STRING", INT_3_RIGHT_PAREN_POS_X, itemPosY, ")");

		}
		else if(menuItem[i].type == FLOAT_ITEM)
		{//floats
				// (
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed,menu.menuGreen,menu.menuBlue, TEXT_ALPHA);
				DrawText("STRING", FLOAT_LEFT_PAREN_POS_X, itemPosY, "(");
				// float number
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);				
				DrawFloat("NUMBR", FLOAT_NUM_POS_X, itemPosY, menuItem[i].floatValue, 1);
				// )
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
				if(menuItem[i].floatValue < 10.0)		//1 figure number
					DrawText("STRING", FLOAT_1_RIGHT_PAREN_POS_X, itemPosY, ")");
				else if(menuItem[i].floatValue < 100.0)	//2 figure number
					DrawText("STRING", FLOAT_2_RIGHT_PAREN_POS_X, itemPosY, ")");
				else 								//3 figure number
					DrawText("STRING", FLOAT_3_RIGHT_PAREN_POS_X, itemPosY, ")");	
		}
		else if(menuItem[i].type == BOOL_ITEM)
		{//bools
			if(menuItem[i].value)
			{//bool on
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
				DrawText("STRING", BOOL_POS_X, itemPosY, BOOL_TRUE_TEXT);
			}
			else
			{//bool off
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
				DrawText("STRING", BOOL_POS_X, itemPosY, BOOL_FALSE_TEXT);
			}
		}
		else if(menuItem[i].type == STRING_ITEM)
		{//strings
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed,menu.menuGreen,menu.menuBlue, TEXT_ALPHA);
				DrawText("STRING", STRING_LEFT_PAREN_POS_X, itemPosY, "(");
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			float stringValueTextLength = DrawTextGetWidth("STRING", STRING_POS_X, itemPosY, menuItem[i].charValue) / 2;
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			DrawText("STRING", stringValueTextLength + STRING_RIGHT_PAREN_POS_X, itemPosY, ")");
		}
		
		//itemPosX += TEXT_SPACING_X;
		itemPosY += TEXT_SPACING_Y;	//makes every item shift lower than the previous item
	}
	
	//arrows
	if(menu.skippedItemCount > 0)
	{//arrow up
		SetUpDraw(TEXT_TYPE, ARROW_SIZE, ARROW_SIZE, 0, 0, 0, TEXT_ALPHA);
		DrawText("STRING", ARROW_UP_LOCATION_X , ARROW_UP_LOCATION_Y, ARROW_UP);
	}
	if(menu.remainingItemCount > 0)
	{//down
		SetUpDraw(TEXT_TYPE, ARROW_SIZE, ARROW_SIZE, 0, 0, 0, TEXT_ALPHA);
		DrawText("STRING", ARROW_DOWN_LOCATION_X , ARROW_DOWN_LOCATION_Y, ARROW_DOWN);
	}

}


