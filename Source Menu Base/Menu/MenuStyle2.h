/**
 *  Menu Style
 *
 *	by: Herr Muskelprotze
 */
 
#pragma once

//	Title formatting
#define MAX_MENU_ITEMS				19
#define TITLE_ALPHA					255
#define TITLE_TEXT_SIZE_X			0.6
#define TITLE_TEXT_SIZE_Y			0.98
#define TITLE_POS_X					0.5
#define TITLE_POS_Y					0.05
/**-------------------------------------------*/	
//	Footer formatting
#define FOOTER_TEXT_TYPE			3
#define FOOTER_TEXT_SIZE_X			0.35
#define FOOTER_TEXT_SIZE_Y			0.35
#define FOOTER_R					255
#define FOOTER_G					255
#define FOOTER_B					255
#define FOOTER_ALPHA				255
#define FOOTER_POS_X				0.05
#define FOOTER_POS_Y				0.975
/**-------------------------------------------*/
//	Menu text formatting
#define TEXT_TYPE					3
#define TEXT_SIZE_X					0.35
#define TEXT_SIZE_Y					0.35
#define TEXT_R						255
#define TEXT_G						255
#define TEXT_B						255
#define TEXT_ALPHA 					255
#define TEXT_POS_X					0.25
#define TEXT_POS_Y					0.1775
#define TEXT_SPACING_X				0.0
#define TEXT_SPACING_Y				0.0375
//	Initial selected item text color options
#define START_RED					255
#define START_GREEN					0
#define START_BLUE					255
/**-------------------------------------------*/
#define BOOL_TRUE_TEXT 				"On"
#define BOOL_FALSE_TEXT				"Off"
#define BOOL_POS_X					TEXT_POS_X + 0.3     	//where the BOOL_TRUE_TEXT and BOOL_FALSE_TEXT text will start relative to TEXT_POS_X
#define INT_NUM_POS_X				TEXT_POS_X + 0.305		// where the integer value will be placed relative to TEXT_POS_X
#define INT_LEFT_PAREN_POS_X		INT_NUM_POS_X - 0.005 	// "(" will be placed relative to INT_NUM_POS_X
#define INT_1_RIGHT_PAREN_POS_X		INT_NUM_POS_X + 0.010   // ")" will be placed with 1 figure number will start relative to INT_NUM_POS_X
#define INT_2_RIGHT_PAREN_POS_X		INT_NUM_POS_X + 0.025 	// ")" will be placed with 2 figure number will start relative to INT_NUM_POS_X
#define INT_3_RIGHT_PAREN_POS_X		INT_NUM_POS_X +	0.040  	// ")" will be placed with 3 figure number will start relative to INT_NUM_POS_X
#define FLOAT_NUM_POS_X				TEXT_POS_X + 0.305		// where the float value will be placed relative to TEXT_POS_X
#define FLOAT_LEFT_PAREN_POS_X		FLOAT_NUM_POS_X - 0.005	// "(" will be placed relative to FLOAT_NUM_POS_X
#define FLOAT_1_RIGHT_PAREN_POS_X	FLOAT_NUM_POS_X + 0.030  // ")" will be placed with 1 figure number will start relative to INT_NUM_POS_X
#define FLOAT_2_RIGHT_PAREN_POS_X	FLOAT_NUM_POS_X + 0.045	// ")" will be placed with 2 figure number will start relative to INT_NUM_POS_X
#define FLOAT_3_RIGHT_PAREN_POS_X	FLOAT_NUM_POS_X + 0.060	// ")" will be placed with 3 figure number will start relative to INT_NUM_POS_X
#define STRING_POS_X				TEXT_POS_X + 0.28
#define STRING_LEFT_PAREN_POS_X		STRING_POS_X - 0.010
#define STRING_RIGHT_PAREN_POS_X	STRING_POS_X + 0.010
/**-------------------------------------------*/
#define ARROW_SIZE					0.5
#define ARROW_UP					"~PAD_UP~"
#define ARROW_UP_LOCATION_X			0.5
#define ARROW_UP_LOCATION_Y			0.135
#define ARROW_DOWN					"~PAD_DOWN~"
#define ARROW_DOWN_LOCATION_X		0.5
#define ARROW_DOWN_LOCATION_Y		0.91
/**-------------------------------------------*/

void DrawTitle(float x, float y, float width, float height, uint r, uint g, uint b, uint a, char *val);
