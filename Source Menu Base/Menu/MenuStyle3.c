/**
 *	Menu Style
 *
 *	by: Three-Socks style (Muskelprotze edit)
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

void MenuStyleConfirmFunction()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
}

void MenuStyleConfirmSubMenu()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
}

void MenuStyleBackSubMenu()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
}

void MenuStylePreviousItem()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
}

void MenuStyleNextItem()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
}

void MenuStyleChangeInt()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
}

void MenuStyleChangeFloat()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
}

void MenuStyleChangeString()
{
	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
}

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

	if (menuItem[menu.highlightedItem].type == INT_ITEM || menuItem[menu.highlightedItem].type == FLOAT_ITEM || menuItem[menu.highlightedItem].type == STRING_ITEM)
		DRAW_FRONTEND_HELPER_TEXT("SCROLL", "PAD_DPAD_LR", 0);
}

void MenuDisplay()
{
	//float itemPosX = TEXT_POS_X;
	float itemPosY = TEXT_POS_Y;
	
	//black box & rectangle
	DrawCurvedWindow(CURVED_WINDOW_POS_X, CURVED_WINDOW_POS_Y, CURVED_WINDOW_SIZE_X, (CURVED_WINDOW_SIZE_Y + CURVED_WINDOW_SIZE_Y_MULT * menu.itemCount), CURVED_WINDOW_ALPHA);
	DrawRectangle(HEADER_LINE_POS_X, HEADER_LINE_POS_Y, HEADER_LINE_SIZE_X, HEADER_LINE_SIZE_Y, HEADER_LINE_R, HEADER_LINE_G, HEADER_LINE_B, HEADER_LINE_ALPHA);
	SetUpDraw(HEADER_TEXT_TYPE, HEADER_TEXT_SIZE_X, HEADER_TEXT_SIZE_Y, HEADER_R, HEADER_G, HEADER_B, HEADER_ALPHA);
	DrawText("STRING", HEADER_POS_X , HEADER_POS_Y, menu.header);
	
	DrawFrontend();
	
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
			if(menuItem[i].value < 10)
			{//1 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_1_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_1_POS_X, itemPosY, menuItem[i].value);
			}
			else if(menuItem[i].value < 100)
			{//2 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_2_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_2_POS_X, itemPosY, menuItem[i].value);
			}
			else if(menuItem[i].value < 1000)	
			{//3 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_3_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_3_POS_X, itemPosY, menuItem[i].value);
			}
			else 
			{
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_INT_4_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawInt("NUMBR", INT_NUM_4_POS_X, itemPosY, menuItem[i].value);
			}
			//right arrow
			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_INT_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 0.0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
		else if(menuItem[i].type == FLOAT_ITEM)
		{//floats
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
			if(menuItem[i].floatValue < 10.0)
			{//1 figure number		
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_FLOAT_1_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawFloat("NUMBR", FLOAT_NUM_1_POS_X, itemPosY, menuItem[i].floatValue, 1);
			}
			else
			{//2 figure number
				DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_FLOAT_2_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
				DrawFloat("NUMBR", FLOAT_NUM_2_POS_X, itemPosY, menuItem[i].floatValue, 1);
			}

			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_FLOAT_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 0.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
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
			DRAW_SPRITE(arrowLeftRight, ARROW_LEFT_STRING_POS_X, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 180.0000, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			float stringValueTextLength = DrawTextGetWidth("STRING", STRING_POS_X, itemPosY, menuItem[i].charValue);
			DRAW_SPRITE(arrowLeftRight, ARROW_RIGHT_STRING_POS_X + stringValueTextLength, itemPosY + ARROW_SPACING, ARROW_SIZE, ARROW_SIZE, 0.0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
		}
	
		//itemPosX += TEXT_SPACING_X;
		itemPosY += TEXT_SPACING_Y;	//makes every item shift lower than the previous item
	}

	//arrows
	if(menu.skippedItemCount > 0)
	{//arrow up
		DRAW_SPRITE(arrowUpDown, ARROW_UP_POS_X, ARROW_UP_POS_Y, ARROW_SIZE, ARROW_SIZE, 0, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
	}
	if(menu.remainingItemCount > 0)
	{//down
		DRAW_SPRITE(arrowUpDown, ARROW_DOWN_POS_X, ARROW_DOWN_POS_Y, ARROW_SIZE, ARROW_SIZE, 180, ARROW_R, ARROW_G, ARROW_B, ARROW_ALPHA);
	}

}


