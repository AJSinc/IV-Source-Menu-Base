/**
 *	Menu Style
 *
 *	by: Three-Socks style (Muskelprotze edit)
 */
 
#pragma once

//	Black box formatting
#define MAX_MENU_ITEMS				14
#define CURVED_WINDOW_POS_X 		0.7200
#define CURVED_WINDOW_POS_Y 		0.163
#define CURVED_WINDOW_SIZE_X 		0.2300
#define CURVED_WINDOW_SIZE_Y		0.09		//initial Y size of box if no items present
#define CURVED_WINDOW_SIZE_Y_MULT	0.04		//depending on how many items there are, it will be multiplied by this
#define CURVED_WINDOW_ALPHA			245
/**-------------------------------------------*/	
//	Header formatting
#define HEADER_TEXT_TYPE			6
#define HEADER_TEXT_SIZE_X			0.3500
#define HEADER_TEXT_SIZE_Y			0.4775
#define HEADER_R					255
#define HEADER_G					255
#define HEADER_B					255
#define HEADER_ALPHA				255
#define HEADER_POS_X				0.7326
#define HEADER_POS_Y				0.1820
// Line under header
#define HEADER_LINE_POS_X			HEADER_POS_X + 0.1027 		//relative to the HEADER_POS_X 0.1853
#define HEADER_LINE_POS_Y			HEADER_POS_Y + 0.0438 		//relative to the HEADER_POS_Y 0.2258
#define HEADER_LINE_SIZE_X			0.205
#define HEADER_LINE_SIZE_Y			0.0030
#define HEADER_LINE_R				255
#define HEADER_LINE_G				255
#define HEADER_LINE_B				255
#define HEADER_LINE_ALPHA			255
/**-------------------------------------------*/
//	Menu text formatting
#define TEXT_TYPE					6
#define TEXT_SIZE_X					0.3100
#define TEXT_SIZE_Y					0.4550
#define TEXT_R						137
#define TEXT_G						137
#define TEXT_B						137
#define TEXT_ALPHA 					255
#define TEXT_POS_X					0.7326
#define TEXT_POS_Y					0.2400
#define TEXT_SPACING_X				0.0
#define TEXT_SPACING_Y				0.0400
//	Initial selected item text color options
#define START_RED					220
#define START_GREEN					20
#define START_BLUE					60
/**-------------------------------------------*/
#define BOOL_TRUE_TEXT 				"On"
#define BOOL_FALSE_TEXT				"Off"
#define BOOL_POS_X					TEXT_POS_X + 0.1674	 	// where the BOOL_TRUE_TEXT and BOOL_FALSE_TEXT text will start relative to TEXT_POS_X	
#define INT_NUM_1_POS_X				TEXT_POS_X + 0.1804	 	// where the integer value will be placed relative to TEXT_POS_X (1 figure number)
#define INT_NUM_2_POS_X				TEXT_POS_X + 0.1694  	// where the integer value will be placed relative to TEXT_POS_X (2 figure number)
#define INT_NUM_3_POS_X				TEXT_POS_X + 0.1554  	// where the integer value will be placed relative to TEXT_POS_X (3 figure number)
#define INT_NUM_4_POS_X				TEXT_POS_X + 0.1474   	// where the integer value will be placed relative to TEXT_POS_X (4 figure number)
#define ARROW_LEFT_INT_1_POS_X		INT_NUM_1_POS_X - 0.010	// left arrow for the ints
#define ARROW_LEFT_INT_2_POS_X		INT_NUM_2_POS_X - 0.010	// < 2 figure
#define ARROW_LEFT_INT_3_POS_X		INT_NUM_3_POS_X - 0.010 // < 3 figure
#define ARROW_LEFT_INT_4_POS_X		INT_NUM_4_POS_X - 0.010	// < 4 figure
#define ARROW_RIGHT_INT_POS_X		INT_NUM_1_POS_X + 0.022	//
#define FLOAT_NUM_1_POS_X			TEXT_POS_X + 0.1644   	// where the float value will be placed relative to TEXT_POS_X (1 figure number)
#define FLOAT_NUM_2_POS_X			TEXT_POS_X + 0.1544	 	// where the float value will be placed relative to TEXT_POS_X (2 figure number)
#define ARROW_LEFT_FLOAT_1_POS_X	FLOAT_NUM_1_POS_X - 0.010	// left arrow for floats
#define ARROW_LEFT_FLOAT_2_POS_X	FLOAT_NUM_2_POS_X - 0.011	// < 2 figure
#define ARROW_RIGHT_FLOAT_POS_X		FLOAT_NUM_1_POS_X + 0.038	// relative to TEXT_POS_X
#define STRING_POS_X				TEXT_POS_X + 0.1554
#define ARROW_LEFT_STRING_POS_X		STRING_POS_X - 0.010
#define ARROW_RIGHT_STRING_POS_X	STRING_POS_X + 0.010
/**-------------------------------------------*/
#define ARROW_SIZE					0.0160
#define ARROW_R						255
#define ARROW_G						255
#define ARROW_B						255
#define ARROW_ALPHA					255
#define ARROW_UP_POS_X				TEXT_POS_X + 0.1074		// relative to TEXT_POS_X
#define ARROW_UP_POS_Y				TEXT_POS_Y - 0.004		// relative to TEXT_POS_Y
#define ARROW_DOWN_POS_X			TEXT_POS_X + 0.1074		// relative to TEXT_POS_X
#define ARROW_DOWN_POS_Y			TEXT_POS_Y + TEXT_SPACING_Y * MAX_MENU_ITEMS		// relative to TEXT_POS_Y + TEXT_SPACING_Y * MAX_MENU_ITEMS
#define ARROW_SPACING				0.0150
/**-------------------------------------------*/

extern Texture arrowUpDown = INVALID_HANDLE;
extern Texture arrowLeftRight = INVALID_HANDLE;

void DrawFrontend();