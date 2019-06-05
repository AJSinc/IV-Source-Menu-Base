/**
 *  Menu Style
 *
 *	by: Motions97
 */
 
#include "Menu.h"

void MenuStyleActivate()
{
	backgroundAlpha = 0;
	lineAlpha = 0;
	itemPosX = TEXT_START_POS_X;
	headerPosX = HEADER_START_POS_X;
	REQUEST_STREAMED_TXD("network", 0);
	while (!HAS_STREAMED_TXD_LOADED("network")) WAIT(0);
	arrowUpDown = GET_TEXTURE_FROM_STREAMED_TXD("network", "ICON_W_ARROW_UP");
	arrowLeftRight = GET_TEXTURE_FROM_STREAMED_TXD("network", "ICON_W_ARROW_RIGHT");
}

void MenuStyleDeactivate()
{
	backgroundAlpha = 0;
	lineAlpha = 0;
	itemPosX = TEXT_START_POS_X;
	headerPosX = HEADER_START_POS_X;
	RELEASE_TEXTURE(arrowUpDown);
	RELEASE_TEXTURE(arrowLeftRight);
	MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED("network");
}

void MenuStyleConfirmFunction(){}
void MenuStyleConfirmSubMenu(){}
void MenuStyleBackSubMenu(){}
void MenuStylePreviousItem(){}
void MenuStyleNextItem(){}
void MenuStyleChangeInt(){}
void MenuStyleChangeFloat(){}
void MenuStyleChangeString(){}

void DrawFrontend()
{
	INIT_FRONTEND_HELPER_TEXT();

	if(menu.level == 0)
		DRAW_FRONTEND_HELPER_TEXT("LEAVE", "INPUT_F_CANCEL", 0);
	else
		DRAW_FRONTEND_HELPER_TEXT("BACK", "INPUT_F_CANCEL", 0);
	
	if(menuItem[menu.highlightedItem].type != SUBMENU_ITEM)
		DRAW_FRONTEND_HELPER_TEXT("CONFIRM", "INPUT_F_ACCEPT", 0);
	else
		DRAW_FRONTEND_HELPER_TEXT("KYB_ENTER", "INPUT_F_ACCEPT", 0);

	if (menuItem[menu.highlightedItem].type == INT_ITEM|| menuItem[menu.highlightedItem].type == FLOAT_ITEM || menuItem[menu.highlightedItem].type == STRING_ITEM)
		DRAW_FRONTEND_HELPER_TEXT("SCROLL", "PAD_DPAD_LR", 0);
}

void MenuDisplay()
{
	float itemPosY = TEXT_POS_Y;
	
	DrawRectangle(0.8180, 0.503, 0.31, -1.0255, 0, 0, 0, backgroundAlpha);	//black dim thingy
	DrawRectangle(0.830, 0.272, 0.33, -0.0115, menu.menuRed, menu.menuGreen, menu.menuBlue, lineAlpha);	// middle line under title
	DrawRectangle(0.663, 0.5, 0.005, 1.0, menu.menuRed, menu.menuGreen, menu.menuBlue, lineAlpha);	//left line going up

	SetUpDraw(HEADER_TEXT_TYPE, HEADER_TEXT_SIZE_X, HEADER_TEXT_SIZE_Y, HEADER_R, HEADER_G, HEADER_B, HEADER_ALPHA);
	DrawText("STRING", headerPosX, HEADER_POS_Y, menu.header);

	if(backgroundAlpha < BACKGROUND_ALPHA)
	{//background box fade in
		backgroundAlpha += 2;
	}
	if(lineAlpha < LINE_ALPHA)
	{//all the lines fade in
		lineAlpha += 5;
	}
	if(itemPosX > TEXT_POS_X)
	{//text scroll in
		itemPosX -= TEXT_SCROLL_SPEED;
	}
	if(headerPosX > HEADER_POS_X)
	{//title scrolling in
		headerPosX -= HEADER_SCROLL_SPEED;
	}
	
	
	DrawFrontend();
	
	for(int i = 0; i < menu.itemCount; i++)
	{
		
		if(menu.highlightedItem == i)
		{//highlight bar
			DrawRectangle(TEXT_POS_X + 0.141, itemPosY + 0.0195, 0.326, -0.0385, menu.menuRed, menu.menuGreen, menu.menuBlue, lineAlpha);
		}
		
		
		SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
		DrawText("STRING", itemPosX, itemPosY, menuItem[i].itemName);
		
		if(menuItem[i].type == INT_ITEM)
		{//ints
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);				
			if(menuItem[i].value < 10)
			{//1 figure number
				DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_LEFT_INT_1_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR",(TEXT_POS_X + INT_NUM_SPACING_1_X), itemPosY, menuItem[i].value);
			}
			else if(menuItem[i].value < 100)
			{//2 figure number
				DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_LEFT_INT_2_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR",(TEXT_POS_X + INT_NUM_SPACING_2_X), itemPosY, menuItem[i].value);
			}
			else if(menuItem[i].value < 1000)	
			{//3 figure number
				DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_LEFT_INT_3_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR",(TEXT_POS_X + INT_NUM_SPACING_3_X), itemPosY, menuItem[i].value);
			}
			else 
			{
				DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_LEFT_INT_4_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR",(TEXT_POS_X + INT_NUM_SPACING_4_X), itemPosY, menuItem[i].value);
			}
			//right arrow
			DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_RIGHT_INT_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 0.0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		else if(menuItem[i].type == FLOAT_ITEM)
		{//floats
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
			if(menuItem[i].floatValue < 10.0)
			{//1 figure number		
				DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_LEFT_FLOAT_1_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawFloat("NUMBR",(TEXT_POS_X + FLOAT_NUM_SPACING_1_X), itemPosY, menuItem[i].floatValue, 1);
			}
			else
			{
				DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_LEFT_FLOAT_2_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawFloat("NUMBR",(TEXT_POS_X + FLOAT_NUM_SPACING_2_X), itemPosY, menuItem[i].floatValue, 1);
			}

			DRAW_SPRITE(arrowLeftRight, TEXT_POS_X + ARROW_RIGHT_FLOAT_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 0.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		else if(menuItem[i].type == BOOL_ITEM)
		{//bools
			if (menuItem[i].value)
			{//true
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, lineAlpha);
				DrawText("STRING", (TEXT_POS_X + BOOL_SPACING_X), itemPosY, BOOL_TRUE_TEXT);
			}
			else
			{//false
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, lineAlpha);
				DrawText("STRING", TEXT_POS_X + BOOL_SPACING_X, itemPosY, BOOL_FALSE_TEXT);
			}
		}
		else if(menuItem[i].type == STRING_ITEM)
		{//strings
			DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_STRING_POS_X, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			float stringValueTextLength = DrawTextGetWidth("STRING", STRING_POS_X, itemPosY, menuItem[i].charValue);
			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_STRING_POS_X + stringValueTextLength, itemPosY + ARROW_LEFT_RIGHT_SPACING_Y, ARROW_SIZE, ARROW_SIZE, 0.0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		
		//itemPosX += TEXT_SPACING_X;
		itemPosY += TEXT_SPACING_Y; //makes every item shift lower than the previous item
	}
	
	//arrows
	if(menu.skippedItemCount > 0)
	{//arrow up
		DRAW_SPRITE(arrowUpDown, TEXT_POS_X + ARROW_DOWN_LOCATION_X, ARROW_UP_LOCATION_Y, ARROW_SIZE, ARROW_SIZE, 0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
	}
	if(menu.remainingItemCount > 0)
	{//down
		DRAW_SPRITE(arrowUpDown, TEXT_POS_X + ARROW_DOWN_LOCATION_X, ARROW_DOWN_LOCATION_Y, ARROW_SIZE, ARROW_SIZE, 180, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
	}

}