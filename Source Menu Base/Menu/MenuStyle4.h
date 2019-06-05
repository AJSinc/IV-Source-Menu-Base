/**
 *  Menu Style
 *
 *	by: Motions97
 */
 
#pragma once

//	Header formatting
#define MAX_MENU_ITEMS				11
#define HEADER_TEXT_TYPE			5
#define HEADER_TEXT_SIZE_X			0.6090
#define HEADER_TEXT_SIZE_Y			0.8865
#define HEADER_R					255
#define HEADER_G					255
#define HEADER_B					255
#define HEADER_ALPHA				255
#define HEADER_START_POS_X			0.803
#define HEADER_SCROLL_SPEED			0.004
#define HEADER_POS_X				0.679
#define HEADER_POS_Y				0.19
//	Fade in
#define LINE_ALPHA					255
#define BACKGROUND_ALPHA			140
/**-------------------------------------------*/
//	Menu text formatting
#define TEXT_TYPE					5
#define TEXT_SIZE_X					0.4930
#define TEXT_SIZE_Y					0.5305
#define TEXT_R						255
#define TEXT_G						255
#define TEXT_B						255
#define TEXT_ALPHA 					255
#define TEXT_START_POS_X			0.8
#define TEXT_SCROLL_SPEED			0.004
#define TEXT_POS_X					0.683
#define TEXT_POS_Y					0.31
#define TEXT_SPACING_X				0.0
#define TEXT_SPACING_Y				0.045
//	Initial selected item text color options
#define START_RED					255
#define START_GREEN					0
#define START_BLUE					0
/**-------------------------------------------*/
#define BOOL_TRUE_TEXT 				"On"
#define BOOL_FALSE_TEXT				"Off"
#define BOOL_SPACING_X				0.232		// where the BOOL_TRUE_TEXT and BOOL_FALSE_TEXT text will start relative to TEXT_POS_X
#define ARROW_LEFT_INT_1_POS_X		0.22		// left arrow for the ints
#define ARROW_LEFT_INT_2_POS_X		0.21		// < 2 figure
#define ARROW_LEFT_INT_3_POS_X		0.205		// < 3 figure
#define ARROW_LEFT_INT_4_POS_X		0.197		// < 4 figure
#define INT_NUM_SPACING_1_X			0.23		// where the integer value will be placed relative to TEXT_POS_X (1 figure number)
#define INT_NUM_SPACING_2_X			0.219  		// where the integer value will be placed relative to TEXT_POS_X (2 figure number)
#define INT_NUM_SPACING_3_X			0.194 		// where the integer value will be placed relative to TEXT_POS_X (3 figure number)
#define INT_NUM_SPACING_4_X			0.187		// where the integer value will be placed relative to TEXT_POS_X (4 figure number)
#define ARROW_RIGHT_INT_POS_X		0.252		// relative to TEXT_POS_X
#define ARROW_LEFT_FLOAT_1_POS_X	0.214		// left arrow for floats
#define ARROW_LEFT_FLOAT_2_POS_X	0.193		// < 2 figure
#define FLOAT_NUM_SPACING_1_X		0.214  		// where the float value will be placed relative to TEXT_POS_X (1 figure number)
#define FLOAT_NUM_SPACING_2_X		0.204	 	// where the float value will be placed relative to TEXT_POS_X (2 figure number)
#define ARROW_RIGHT_FLOAT_POS_X		0.252		// relative to TEXT_POS_X
#define STRING_POS_X				TEXT_POS_X + 0.194
#define ARROW_LEFT_STRING_POS_X		STRING_POS_X - 0.010
#define ARROW_RIGHT_STRING_POS_X	STRING_POS_X + 0.010
/**-------------------------------------------*/
#define ARROW_SIZE					0.0160
#define ARROW_R						255	
#define ARROW_G						255	
#define ARROW_B						255	
#define ARROW_ALPHA					255	
#define ARROW_UP_LOCATION_X			0.157		// relative to TEXT_POS_X
#define ARROW_UP_LOCATION_Y			TEXT_POS_Y - 0.017		// relative to TEXT_POS_Y
#define ARROW_DOWN_LOCATION_X		0.157		// relative to TEXT_POS_X
#define ARROW_DOWN_LOCATION_Y		TEXT_POS_Y - 0.14 + TEXT_SPACING_Y * MAX_MENU_ITEMS	// relative to TEXT_POS_Y + TEXT_SPACING_Y * MAX_MENU_ITEMS
#define ARROW_LEFT_RIGHT_SPACING_Y	0.0150
/**-------------------------------------------*/

extern int backgroundAlpha = 0;
extern int lineAlpha = 0;
extern float itemPosX = 0.0f;
extern float headerPosX = 0.0f;
extern Texture arrowUpDown = INVALID_HANDLE;
extern Texture arrowLeftRight = INVALID_HANDLE;

void DrawFrontend();
