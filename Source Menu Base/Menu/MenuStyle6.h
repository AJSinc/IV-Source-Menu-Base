/**
 *  Menu Style
 *	Replicates the GTA: Online Interaction menu 
 *	by: Buffeting
 */
 
#pragma once

// Background Boxes
#define MAX_MENU_ITEMS				7
#define TOP_RECTANGLE_SIZE_X 		0.226
#define TOP_RECTANGLE_SIZE_Y		0.090
#define TOP_RECTANGLE_POS_X			0.05//0.667
#define TOP_RECTANGLE_POS_Y			0.0653
#define HEADER_RECTANGLE_POS_X		TOP_RECTANGLE_POS_X
#define HEADER_RECTANGLE_POS_Y		TOP_RECTANGLE_POS_Y + TOP_RECTANGLE_SIZE_Y
#define HEADER_RECTANGLE_SIZE_X		TOP_RECTANGLE_SIZE_X
#define HEADER_RECTANGLE_SIZE_Y		0.0351851
#define BOTTOM_RECTANGLE_SIZE_X 	TOP_RECTANGLE_SIZE_X
#define BOTTOM_RECTANGLE_SIZE_Y		0.3125
#define BOTTOM_RECTANGLE_MULT_Y		0.03452380952
#define BOTTOM_RECTANGLE_POS_X		TOP_RECTANGLE_POS_X
#define BOTTOM_RECTANGLE_POS_Y		HEADER_RECTANGLE_POS_Y + HEADER_RECTANGLE_SIZE_Y

/**-------------------------------------------*/
#define TITLE_TEXT_TYPE				5
#define TITLE_TEXT_SIZE_X			0.26
#define TITLE_TEXT_SIZE_Y			0.64218
#define TITLE_R						255
#define TITLE_G						255
#define TITLE_B						255
#define TITLE_ALPHA					255
#define TITLE_POS_X					TOP_RECTANGLE_POS_X + TOP_RECTANGLE_SIZE_X / 2.0
#define TITLE_POS_Y					0.0958
//	Header formatting
#define HEADER_TEXT_TYPE			5
#define HEADER_TEXT_SIZE_X			0.17
#define HEADER_TEXT_SIZE_Y			0.309375
#define HEADER_R					75
#define HEADER_G					110
#define HEADER_B					153
#define HEADER_ALPHA				255
#define HEADER_POS_X				BOTTOM_RECTANGLE_POS_X + 0.00625
#define HEADER_POS_Y				0.16340
/**-------------------------------------------*/
#define TEXT_TYPE					5
#define TEXT_SIZE_X					0.17
#define TEXT_SIZE_Y					0.309375
#define TEXT_R						240
#define TEXT_G						240
#define TEXT_B						240
#define TEXT_ALPHA 					255
#define TEXT_POS_X					BOTTOM_RECTANGLE_POS_X + 0.00625
#define TEXT_POS_Y					0.19801
#define TEXT_SPACING_X				0.0
#define TEXT_SPACING_Y				0.0347
#define HIGHLIGHT_RETANGLE_SIZE_X	TOP_RECTANGLE_SIZE_X
#define HIGHLIGHT_RETANGLE_SIZE_Y	0.0347
#define HIGHLIGHT_RETANGLE_POS_X	TEXT_POS_X - 0.00625
#define HIGHLIGHT_RETANGLE_POS_Y	itemPosY - 0.00735
//	Initial selected item text color options
#define START_RED					0
#define START_GREEN					0
#define START_BLUE					0
/**-------------------------------------------*/
#define BOOL_TRUE_TEXT 				"On"
#define BOOL_FALSE_TEXT				"Off"
/**-------------------------------------------*/
#define ARROW_SIZE					0.25
#define ARROW_UP					"~PAD_UP~"
#define ARROW_UP_LOCATION_X			BOTTOM_RECTANGLE_POS_X + TOP_RECTANGLE_SIZE_X / 2.0
#define ARROW_UP_LOCATION_Y			-0.00580 + TEXT_POS_Y + TEXT_SPACING_Y * MAX_MENU_ITEMS
#define ARROW_DOWN					"~PAD_DOWN~"
#define ARROW_DOWN_LOCATION_X		ARROW_UP_LOCATION_X
#define ARROW_DOWN_LOCATION_Y		ARROW_UP_LOCATION_Y + 0.014444
#define ARROW_RECTANGLE_POS_X		TOP_RECTANGLE_POS_X
#define ARROW_RECTANGLE_POS_Y		BOTTOM_RECTANGLE_POS_Y + BOTTOM_RECTANGLE_MULT_Y * menu.itemCount + (1.0 / 1080.0)
#define ARROW_RECTANGLE_SIZE_X		TOP_RECTANGLE_SIZE_X
#define ARROW_RECTANGLE_SIZE_Y		0.0351851
#define ARROW_LEFT					"<"
#define ARROW_RIGHT					">"
#define ARROW_RIGHT_STRING_POS_X	TEXT_POS_X + 0.20975//STRING_POS_X + 0.20975
/**-------------------------------------------*/
#define MAX_CHAR_SCROLL 			23
#define MAX_STRING_ITEM_CHAR_SCROLL 18

extern int stringSliderPos = 0;
extern int stringSliderPosTime = 0;
extern int stringItemSliderPos = 0;
extern int stringItemSliderPosTime = 0;

#define ResetTick()\
	stringSliderPos = 0;\
	stringSliderPosTime = GetTickCount() + 1000;\
	stringItemSliderPos = 0;\
	stringItemSliderPosTime = GetTickCount() + 1000;
