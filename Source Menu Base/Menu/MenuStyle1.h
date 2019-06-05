/**
 *	Menu Style
 *
 *	by: Buffeting
 */
 
#pragma once

//	Black box formatting
#define MAX_MENU_ITEMS				20
#define CURVED_WINDOW_POS_X 		0.62
#define CURVED_WINDOW_POS_Y 		0.0
#define CURVED_WINDOW_SIZE_X 		0.29
#define CURVED_WINDOW_SIZE_Y		0.09	//initial Y size of box if no items present
#define CURVED_WINDOW_SIZE_Y_MULT	0.02265	//depending on how many items there are, it will be multiplied by this
#define CURVED_WINDOW_ALPHA			245
/**-------------------------------------------*/	
//	Header formatting
#define HEADER_TEXT_TYPE			3
#define HEADER_TEXT_SIZE_X			0.35
#define HEADER_TEXT_SIZE_Y			0.35
#define HEADER_R					140
#define HEADER_G					140
#define HEADER_B					140
#define HEADER_ALPHA				255
#define HEADER_POS_X				0.64
#define HEADER_POS_Y				0.053
/**-------------------------------------------*/
//	Menu text formatting
#define TEXT_TYPE					3
#define TEXT_SIZE_X					0.33
#define TEXT_SIZE_Y					0.33
#define TEXT_R						140
#define TEXT_G						140
#define TEXT_B						140
#define TEXT_ALPHA 					255
#define TEXT_POS_X					0.64
#define TEXT_POS_Y					0.0845
#define TEXT_SPACING_X				0.0
#define TEXT_SPACING_Y				0.022
//	Initial selected item text color options
#define START_RED					240
#define START_GREEN					160
#define START_BLUE					0
/**-------------------------------------------*/
#define BOOL_TRUE_TEXT 				"On"
#define BOOL_FALSE_TEXT				"Off"		
#define BOOL_POS_X					TEXT_POS_X + 0.23	 // where the BOOL_TRUE_TEXT and BOOL_FALSE_TEXT text will start relative to TEXT_POS_X	
#define INT_NUM_POS_X				TEXT_POS_X + 0.2363  // where the integer value will be placed relative to TEXT_POS_X
#define FLOAT_NUM_POS_X				TEXT_POS_X + 0.230 	 // where the float value will be placed relative to TEXT_POS_X
#define STRING_POS_X				TEXT_POS_X + 0.18
//#define ARROW_LEFT_STRING_POS_X	STRING_POS_X - 0.010
//#define ARROW_RIGHT_STRING_POS_X	STRING_POS_X + 0.010
/**-------------------------------------------*/
#define ARROW_SIZE					0.45
#define ARROW_UP					"~PAD_UP~"
#define ARROW_UP_LOCATION_X			0.623
#define ARROW_UP_LOCATION_Y			0.050
#define ARROW_DOWN					"~PAD_DOWN~"
#define ARROW_DOWN_LOCATION_X		0.623
#define ARROW_DOWN_LOCATION_Y		0.080			
/**-------------------------------------------*/
