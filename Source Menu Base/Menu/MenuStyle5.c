/**
 *  Menu Style
 *
 *	by: Buffeting
 */
 
#include "Menu.h"

void MenuStyleActivate()
{
	REQUEST_STREAMED_TXD("network", 0);
	while (!HAS_STREAMED_TXD_LOADED("network")) WAIT(0);
	arrowUpDown = GET_TEXTURE_FROM_STREAMED_TXD("network", "ICON_W_ARROW_UP");
	arrowLeftRight = GET_TEXTURE_FROM_STREAMED_TXD("network", "ICON_W_ARROW_RIGHT");
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
}

void MenuStyleDeactivate()
{
	RELEASE_TEXTURE(arrowUpDown);
	RELEASE_TEXTURE(arrowLeftRight);
	MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED("network");
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_UNREADY");
}

void MenuStyleConfirmFunction(){}
void MenuStyleConfirmSubMenu(){}
void MenuStyleBackSubMenu(){}
void MenuStylePreviousItem(){}
void MenuStyleNextItem(){}
void MenuStyleChangeInt(){}
void MenuStyleChangeFloat(){}
void MenuStyleChangeString(){}

void SetupDrawStyle(int type, float width, float height, int r, uint g, int b, int a)
{
	SET_TEXT_FONT(0);

	SET_TEXT_BACKGROUND(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	SET_TEXT_EDGE(0, 0, 0, 0, 255);

	if(type == 1)
		SET_TEXT_BACKGROUND(1);
	else if(type == 2)
		SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
	else if(type == 3)
		SET_TEXT_EDGE(1, 0, 0, 0, 255);
	else if(type == 4)
		SET_TEXT_EDGE(1, 235, 235, 235, 255);

	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_SCALE(width, height);
	SET_TEXT_PROPORTIONAL(1);

	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(1);
	SET_TEXT_RIGHT_JUSTIFY(0);
}

void MenuDisplay()
{
	float itemPosY = TEXT_POS_Y;
	float itemTextLength;
	
	SetupDrawStyle(HEADER_TEXT_TYPE, HEADER_TEXT_SIZE_X, HEADER_TEXT_SIZE_Y, HEADER_R, HEADER_G, HEADER_B, HEADER_ALPHA);
	DrawText("STRING", HEADER_POS_X, HEADER_POS_Y, menu.header);

	for(int i = 0; i < menu.itemCount; i++)
	{
		
		if(menu.highlightedItem == i)
		{//highlight bar
			SetupDrawStyle(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
		}
		else
		{
			SetupDrawStyle(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
		}
		itemTextLength = DrawTextGetWidth("STRING", TEXT_POS_X, itemPosY, menuItem[i].itemName) / 2.0;
		
		if(menuItem[i].type == INT_ITEM)
		{//ints
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);				
			if(menuItem[i].value < 10)
			{//1 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_1_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_1_POS_X + itemTextLength, itemPosY, menuItem[i].value);
			}
			else if(menuItem[i].value < 100)
			{//2 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_2_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_2_POS_X + itemTextLength, itemPosY, menuItem[i].value);
			}
			else if(menuItem[i].value < 1000)	
			{//3 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_3_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_3_POS_X + itemTextLength, itemPosY, menuItem[i].value);
			}
			else 
			{
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_4_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_4_POS_X + itemTextLength, itemPosY, menuItem[i].value);
			}
			//right arrow
			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_INT_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 0.0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		else if(menuItem[i].type == FLOAT_ITEM)
		{//floats
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
			if(menuItem[i].floatValue < 10.0)
			{//1 figure number		
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_FLOAT_1_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawFloat("NUMBR", FLOAT_NUM_1_POS_X + itemTextLength, itemPosY, menuItem[i].floatValue, 1);
			}
			else
			{//2 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_FLOAT_2_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawFloat("NUMBR", FLOAT_NUM_2_POS_X + itemTextLength, itemPosY, menuItem[i].floatValue, 1);
			}
			//right arrow
			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_FLOAT_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 0.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		else if(menuItem[i].type == BOOL_ITEM)
		{//bools
			if (menuItem[i].value)
			{//true
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
				DrawText("STRING", BOOL_SPACING_X + itemTextLength, itemPosY, BOOL_TRUE_TEXT);
			}
			else
			{//false
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
				DrawText("STRING", BOOL_SPACING_X + itemTextLength, itemPosY, BOOL_FALSE_TEXT);
			}
		}
		else if(menuItem[i].type == STRING_ITEM)
		{//strings
			float stringSizeX = TEXT_SIZE_X;
			DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_STRING_POS_X + itemTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
			if(strlen(menuItem[i].charValue) > 15)
			{
				stringSizeX = TEXT_SIZE_X -((strlen(menuItem[i].charValue) - 15) * 0.008);
			}
			SetUpDraw(TEXT_TYPE, stringSizeX, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			float stringValueTextLength = DrawTextGetWidth("STRING", STRING_POS_X + itemTextLength, itemPosY, menuItem[i].charValue);
			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_STRING_POS_X + itemTextLength + stringValueTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 0.0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		
		itemPosY += TEXT_SPACING_Y;	//makes every item shift lower than the previous item
	}
	
	//arrows
	if(menu.skippedItemCount > 0)
	{//arrow up
		DRAW_SPRITE(arrowUpDown, ARROW_UP_POS_X, ARROW_UP_POS_Y, ARROW_SIZE, ARROW_SIZE, 0, menu.menuRed, menu.menuGreen, menu.menuBlue, ARROW_ALPHA);
	}
	if(menu.remainingItemCount > 0)
	{//down
		DRAW_SPRITE(arrowUpDown, ARROW_DOWN_POS_X, ARROW_DOWN_POS_Y, ARROW_SIZE, ARROW_SIZE, 180, menu.menuRed, menu.menuGreen, menu.menuBlue, ARROW_ALPHA);
	}

}