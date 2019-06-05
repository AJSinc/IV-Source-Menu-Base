/**
 *  Menu Style
 *
 *	by: Buffeting
 */
 
#pragma once

//	Header formatting
#define MAX_MENU_ITEMS				15
#define HEADER_TEXT_TYPE			3
#define HEADER_TEXT_SIZE_X			0.6090
#define HEADER_TEXT_SIZE_Y			0.8865
#define HEADER_R					180
#define HEADER_G					120
#define HEADER_B					205
#define HEADER_ALPHA				255
#define HEADER_POS_X				0.5
#define HEADER_POS_Y				0.10
/**-------------------------------------------*/
//	Menu text formatting
#define TEXT_TYPE					3
#define TEXT_SIZE_X					0.4930
#define TEXT_SIZE_Y					0.5305
#define TEXT_R						150
#define TEXT_G						140
#define TEXT_B						225
#define TEXT_ALPHA 					255
#define TEXT_POS_X					0.5
#define TEXT_POS_Y					0.19
#define TEXT_SPACING_X				0.0
#define TEXT_SPACING_Y				0.04
//	Initial selected item text color options
#define START_RED					245
#define START_GREEN					245
#define START_BLUE					245
/**-------------------------------------------*/
#define BOOL_TRUE_TEXT 				"On"
#define BOOL_FALSE_TEXT				"Off"
#define BOOL_SPACING_X				TEXT_POS_X + 0.05		// where the BOOL_TRUE_TEXT and BOOL_FALSE_TEXT text will start relative to TEXT_POS_X
#define INT_NUM_1_POS_X				TEXT_POS_X + 0.08		// where the integer value will be placed relative to TEXT_POS_X (1 figure number)
#define INT_NUM_2_POS_X				TEXT_POS_X + 0.07  		// where the integer value will be placed relative to TEXT_POS_X (2 figure number)
#define INT_NUM_3_POS_X				TEXT_POS_X + 0.06 		// where the integer value will be placed relative to TEXT_POS_X (3 figure number)
#define INT_NUM_4_POS_X				TEXT_POS_X + 0.05		// where the integer value will be placed relative to TEXT_POS_X (4 figure number)
#define ARROW_LEFT_INT_1_POS_X		INT_NUM_1_POS_X - 0.010	// left arrow for the ints
#define ARROW_LEFT_INT_2_POS_X		INT_NUM_2_POS_X - 0.010	// < 2 figure
#define ARROW_LEFT_INT_3_POS_X		INT_NUM_3_POS_X - 0.010 // < 3 figure
#define ARROW_LEFT_INT_4_POS_X		INT_NUM_4_POS_X - 0.010	// < 4 figure
#define ARROW_RIGHT_INT_POS_X		INT_NUM_1_POS_X + 0.037	// relative to TEXT_POS_X
#define FLOAT_NUM_1_POS_X			TEXT_POS_X + 0.08  		// where the float value will be placed relative to TEXT_POS_X (1 figure number)
#define FLOAT_NUM_2_POS_X			TEXT_POS_X + 0.07	 	// where the float value will be placed relative to TEXT_POS_X (2 figure number)
#define ARROW_LEFT_FLOAT_1_POS_X	FLOAT_NUM_1_POS_X - 0.012// left arrow for floats
#define ARROW_LEFT_FLOAT_2_POS_X	FLOAT_NUM_2_POS_X - 0.012// < 2 figure
#define ARROW_RIGHT_FLOAT_POS_X		FLOAT_NUM_1_POS_X + 0.055// relative to TEXT_POS_X
#define STRING_POS_X				TEXT_POS_X + 0.07
#define ARROW_LEFT_STRING_POS_X		STRING_POS_X - 0.010
#define ARROW_RIGHT_STRING_POS_X	STRING_POS_X + 0.025
/**-------------------------------------------*/
#define ARROW_SIZE					0.0160
#define ARROW_R						255	
#define ARROW_G						255	
#define ARROW_B						255	
#define ARROW_ALPHA					255	
#define ARROW_UP_POS_X				TEXT_POS_X + 0.0	// relative to TEXT_POS_X
#define ARROW_UP_POS_Y				TEXT_POS_Y - 0.03	// relative to TEXT_POS_Y
#define ARROW_DOWN_POS_X			TEXT_POS_X + 0.0	// relative to TEXT_POS_X
#define ARROW_DOWN_POS_Y			TEXT_POS_Y - 0.01	// relative to TEXT_POS_Y
#define ARROW_LEFT_RIGHT_SPACING_Y	0.0150
/**-------------------------------------------*/


extern Texture arrowUpDown = INVALID_HANDLE;
extern Texture arrowLeftRight = INVALID_HANDLE;

void SetupDrawStyle(int type, float width, float height, int r, uint g, int b, int a);
