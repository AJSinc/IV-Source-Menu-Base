/**
 *  Menu Style
 *	Replicates the GTA: Online Interaction menu 
 *	by: Buffeting
 */

#include "Menu.h"

void MenuStyleActivate()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
	ResetTick();
}

void MenuStyleDeactivate()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
}

void MenuStyleConfirmFunction()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
}

void MenuStyleConfirmSubMenu()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
	ResetTick();
}

void MenuStyleBackSubMenu()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
	ResetTick();
}

void MenuStylePreviousItem()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
	ResetTick();
}

void MenuStyleNextItem()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
	ResetTick();
}

void MenuStyleChangeInt()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
}

void MenuStyleChangeFloat()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
}

void MenuStyleChangeString()
{
	PLAY_AUDIO_EVENT("RADIO_RETUNE_BEEP");
	stringItemSliderPos = 0;
	stringItemSliderPosTime = GetTickCount() + 1000;
}

//actual menu display
void MenuDisplay()
{
	int r, g, b;
	//float itemPosX = TEXT_POS_X;
	float itemPosY = TEXT_POS_Y;
	
	DrawRectangle2(TOP_RECTANGLE_POS_X, TOP_RECTANGLE_POS_Y, TOP_RECTANGLE_SIZE_X, TOP_RECTANGLE_SIZE_Y, 45, 110, 185, 255); // top box
	DrawRectangle2(HEADER_RECTANGLE_POS_X, HEADER_RECTANGLE_POS_Y, HEADER_RECTANGLE_SIZE_X, HEADER_RECTANGLE_SIZE_Y, 0, 0, 0, 255); // header box
	DrawRectangle2(BOTTOM_RECTANGLE_POS_X, BOTTOM_RECTANGLE_POS_Y, BOTTOM_RECTANGLE_SIZE_X, BOTTOM_RECTANGLE_MULT_Y * menu.itemCount, 0, 0, 0, 140); // bottom box
	
	SetUpDraw(TITLE_TEXT_TYPE, TITLE_TEXT_SIZE_X, TITLE_TEXT_SIZE_Y, TITLE_R, TITLE_G, TITLE_B, TITLE_ALPHA);
	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(1);
	SET_TEXT_RIGHT_JUSTIFY(0);
	DrawText("STRING", TITLE_POS_X , TITLE_POS_Y, MENU_TITLE);
	
	SetUpDraw(HEADER_TEXT_TYPE, HEADER_TEXT_SIZE_X, HEADER_TEXT_SIZE_Y, HEADER_R, HEADER_G, HEADER_B, HEADER_ALPHA);
	DrawText("STRING", HEADER_POS_X , HEADER_POS_Y, menu.header);
	
	for(int i = 0; i < menu.itemCount; i++)
	{		
		//get string length
		int strlength = strlen(menuItem[i].itemName);
		int strScriptCharLength = 0;
		int stringPos = 0;
		int stringStopPos = 0;
		
		if(strlength > MAX_CHAR_SCROLL)
		{//text scrolling code
			//prevent special characters such as ~PAD_UP~ from counting more than once
			strScriptCharLength = strlenScript(menuItem[i].itemName);
		}
	
		if(menu.highlightedItem == i)
		{//selected item text
			if(strScriptCharLength > MAX_CHAR_SCROLL)
			{//text scrolling code
				if(stringSliderPosTime < GetTickCount())
				{
					if(stringSliderPos + MAX_CHAR_SCROLL < strScriptCharLength)
					{
						if(charAt(menuItem[i].itemName, stringSliderPos) == '~')
						{
							stringSliderPos = indexOfAfterIndex(menuItem[i].itemName, '~', stringSliderPos) + 1;
						}
						else
						{
							stringSliderPos++;
						}
						stringSliderPosTime = GetTickCount() + 250;
					}
					else
					{
						if(stringSliderPosTime + 750 < GetTickCount())
						{
							stringSliderPos = 0;
							stringSliderPosTime = GetTickCount() + 1000;
						}
					}
				}
				stringPos = stringSliderPos;
			}
			r = menu.menuRed, g = menu.menuGreen, b = menu.menuBlue;
			DrawRectangle2(HIGHLIGHT_RETANGLE_POS_X, HIGHLIGHT_RETANGLE_POS_Y, HIGHLIGHT_RETANGLE_SIZE_X, HIGHLIGHT_RETANGLE_SIZE_Y, 255, 255, 255, 255);
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, menu.menuRed, menu.menuGreen, menu.menuBlue, TEXT_ALPHA);
			//
		}
		else
		{//non-selected item text
			r = TEXT_R, g = TEXT_G, b = TEXT_B;
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, TEXT_R, TEXT_G, TEXT_B, TEXT_ALPHA);
			//
		}
		
		if(strScriptCharLength > MAX_CHAR_SCROLL)
		{//text scrolling code
			stringStopPos = stringPos + MAX_CHAR_SCROLL;
			
			for(int j = stringPos; j < stringStopPos; j++)
			{
				if(charAt(menuItem[i].itemName, j) == '~')
				{
					//end of a ~
					if(j > 0 && charAt(menuItem[i].itemName, j-1) != ' ')
					{
						stringPos = indexOfBeforeIndex(menuItem[i].itemName, '~', j);
					}
					//starting of a ~
					else
					{
						stringStopPos += (indexOfAfterIndex(menuItem[i].itemName, '~', j) - j);
						j = indexOfAfterIndex(menuItem[i].itemName, '~', j) + 1;
					}
				}
			}
			
			DrawText("STRING", TEXT_POS_X, itemPosY, substring(menuItem[i].itemName, stringPos, stringStopPos));
		}
		else
		{
			DrawText("STRING", TEXT_POS_X, itemPosY, menuItem[i].itemName);
		}
		
		//special items
		if(menuItem[i].type == INT_ITEM)
		{//ints
			char buffer[16];
			strcpy_s(buffer, "< ");
			straddi_s(buffer, menuItem[i].value);
			stradd_s(buffer, " >");
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, r, g, b, TEXT_ALPHA);
			SET_TEXT_RIGHT_JUSTIFY(true);
			SET_TEXT_WRAP(0.0, ARROW_RIGHT_STRING_POS_X);
			DrawText("STRING", 0.0, itemPosY, buffer);
		}
		else if(menuItem[i].type == FLOAT_ITEM)
		{//floats
			char buffer[32];
			strcpy_s(buffer, "< ");
			straddf_b(buffer, menuItem[i].floatValue, 1);
			stradd_s(buffer, " >");
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, r, g, b, TEXT_ALPHA);
			SET_TEXT_RIGHT_JUSTIFY(true);
			SET_TEXT_WRAP(0.0, ARROW_RIGHT_STRING_POS_X);
			DrawText("STRING", 0.0, itemPosY, buffer);
		}
		else if(menuItem[i].type == BOOL_ITEM)
		{//bools
			SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, r, g, b, TEXT_ALPHA);
			SET_TEXT_RIGHT_JUSTIFY(true);
			SET_TEXT_WRAP(0.0, ARROW_RIGHT_STRING_POS_X);
			DrawText("STRING", 0.0, itemPosY, menuItem[i].value ? BOOL_TRUE_TEXT : BOOL_FALSE_TEXT);
		}
		else if(menuItem[i].type == STRING_ITEM)
		{//strings
			float stringSizeX = TEXT_SIZE_X;
			strScriptCharLength = 0;
			strlength = strlen(menuItem[i].charValue);
			
			if(strlength > MAX_STRING_ITEM_CHAR_SCROLL)
			{//text scrolling code
				//prevent special characters such as ~PAD_UP~ from counting more than once
				strScriptCharLength = strlenScript(menuItem[i].charValue);
				if(strScriptCharLength > MAX_STRING_ITEM_CHAR_SCROLL)
				{
					if(menu.highlightedItem == i)
					{//selected item text
						if(stringItemSliderPosTime < GetTickCount())
						{
							if(stringItemSliderPos + MAX_STRING_ITEM_CHAR_SCROLL < strScriptCharLength)
							{
								if(charAt(menuItem[i].charValue, stringItemSliderPos) == '~')
								{
									//starting of a ~
									stringItemSliderPos = indexOfAfterIndex(menuItem[i].charValue, '~', stringItemSliderPos) + 1;
								}
								else
								{
									stringItemSliderPos++;
								}
								stringItemSliderPosTime = GetTickCount() + 250;
							}
							else
							{
								if(stringItemSliderPosTime + 750 < GetTickCount())
								{
									stringItemSliderPos = 0;
									stringItemSliderPosTime = GetTickCount() + 1000;
								}
							}
						}
						stringPos = stringItemSliderPos;
					}
					
					int j;
					stringStopPos = stringPos + MAX_STRING_ITEM_CHAR_SCROLL;
					for(j = stringPos; j < stringStopPos; j++)
					{
						if(charAt(menuItem[i].charValue, j) ==  '~')
						{
							//end of a ~
							if(j > 0 && charAt(menuItem[i].charValue, j-1) != ' ')
							{
								stringPos = indexOfBeforeIndex(menuItem[i].charValue, '~', j);
							}
							//starting of a ~
							else
							{
								stringStopPos += (indexOfAfterIndex(menuItem[i].charValue, '~', j) - j);
								j = indexOfAfterIndex(menuItem[i].charValue, '~', j) + 1;
							}
						}
					}
				}
			}
			
			//text
			char buffer[64];
			strcpy_s(buffer, "< ");
			stradd_s(buffer, (strScriptCharLength > MAX_STRING_ITEM_CHAR_SCROLL) ? substring(menuItem[i].charValue, stringPos, stringStopPos) : menuItem[i].charValue);
			//stradd_s(buffer, menuItem[i].charValue);
			stradd_s(buffer, " >");
			SetUpDraw(TEXT_TYPE, stringSizeX, TEXT_SIZE_Y, r, g, b, TEXT_ALPHA);
			SET_TEXT_RIGHT_JUSTIFY(true);
			SET_TEXT_WRAP(0.0, ARROW_RIGHT_STRING_POS_X);
			DrawText("STRING", 0.0, itemPosY, buffer);
		}
		
		
		//itemPosX += TEXT_SPACING_X;
		itemPosY += TEXT_SPACING_Y;	//makes every item shift lower than the previous item
	}
	if(menu.itemCount > 0)
	{
		int selectedItem = menu.highlightedItem + menu.skippedItemCount + 1;
		int totalItems = menu.skippedItemCount + menu.itemCount + menu.remainingItemCount;
		char buffer[16];
		strcpy_s(buffer, " ");
		straddi_s(buffer, selectedItem);
		stradd_s(buffer, " / ");
		straddi_s(buffer, totalItems);
		SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, HEADER_R, HEADER_G, HEADER_B, TEXT_ALPHA);
		SET_TEXT_RIGHT_JUSTIFY(true);
		SET_TEXT_WRAP(0.0, ARROW_RIGHT_STRING_POS_X);
		DrawText("STRING", 0.0, HEADER_POS_Y, buffer);
	}
	
	if(menu.skippedItemCount > 0 || menu.remainingItemCount > 0)
	{//arrow up/down
		DrawRectangle2(ARROW_RECTANGLE_POS_X, ARROW_RECTANGLE_POS_Y, ARROW_RECTANGLE_SIZE_X, ARROW_RECTANGLE_SIZE_Y, 0, 0, 0, 200); // bottom box
		SetUpDraw(TEXT_TYPE, ARROW_SIZE, ARROW_SIZE, 0, 0, 0, TEXT_ALPHA);
		DrawText("STRING", ARROW_UP_LOCATION_X , ARROW_UP_LOCATION_Y, ARROW_UP);
		SetUpDraw(TEXT_TYPE, ARROW_SIZE, ARROW_SIZE, 0, 0, 0, TEXT_ALPHA);
		DrawText("STRING", ARROW_DOWN_LOCATION_X , ARROW_DOWN_LOCATION_Y, ARROW_DOWN);
	}
	
	if(strlen(menuItem[menu.highlightedItem].itemInfo) > 0) // Item info
	{
		r = TEXT_R, g = TEXT_G, b = TEXT_B;
		float itemInfoPosY = (menu.skippedItemCount > 0 || menu.remainingItemCount > 0) ? (ARROW_RECTANGLE_POS_Y + ARROW_RECTANGLE_SIZE_Y + 0.0027f) : (BOTTOM_RECTANGLE_POS_Y + BOTTOM_RECTANGLE_MULT_Y * menu.itemCount) + 0.0027f;
		SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, r, g, b, TEXT_ALPHA);
		int lineCount = indexOfStr(menuItem[menu.highlightedItem].itemInfo, "~n~");
		if(lineCount == -1) // No newlines
		{
			lineCount = 1;
			DrawText("STRING", TEXT_POS_X , (itemInfoPosY + 0.0075249), menuItem[menu.highlightedItem].itemInfo);
		}
		else
		{
			int index = lineCount;
			lineCount = 1;
			DrawText("STRING", TEXT_POS_X , (itemInfoPosY + 0.0075249), substring(menuItem[menu.highlightedItem].itemInfo, 0, index));
			//itemInfoPosY -= 0.0075249;
			while(true)
			{
				lineCount++;
				int prevIndex = (index + 3);
				index = indexOfStrAfterIndex(menuItem[menu.highlightedItem].itemInfo, "~n~", (prevIndex - 1));
				SetUpDraw(TEXT_TYPE, TEXT_SIZE_X, TEXT_SIZE_Y, r, g, b, TEXT_ALPHA);
				//if (lineCount == 2) itemInfoPosY -= 0.0075249;
				if(index == -1)
				{
					
					index = strlen(menuItem[menu.highlightedItem].itemInfo);
					DrawText("STRING", TEXT_POS_X, (itemInfoPosY + (TEXT_SPACING_Y * (lineCount - 1))), substring(menuItem[menu.highlightedItem].itemInfo, prevIndex, index));
					if (lineCount > 2) itemInfoPosY += 0.0075249;
					break;
				}
				DrawText("STRING", TEXT_POS_X , (itemInfoPosY + (TEXT_SPACING_Y * (lineCount - 1))), substring(menuItem[menu.highlightedItem].itemInfo, prevIndex, index));
				if(lineCount == 2) itemInfoPosY -= 0.0075249;
				//if (lineCount == 2) itemInfoPosY += 0.0075249;
			}
		}
		float rectSize = (BOTTOM_RECTANGLE_MULT_Y * lineCount);
		if (lineCount > 2)
		{
			rectSize -= (0.0075249);
		}
		DrawRectangle2(BOTTOM_RECTANGLE_POS_X, itemInfoPosY, BOTTOM_RECTANGLE_SIZE_X, rectSize, 0, 0, 0, 140); // bottom box
	}
}