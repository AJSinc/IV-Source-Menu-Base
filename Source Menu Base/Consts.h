/**
 *	Menu Constants
 *	
 *	This file contains all settings/constants for the menu
 */

#pragma once

#pragma region Required Settings //{

#define MENU_TITLE						"Source Menu"
#define MENU_STYLE						6

//Misc options
#define MAX_MENU_LEVELS					5
#define MENU_SCROLL_WAIT_TIME			200	//time in MS
#define MENU_SCROLL_FAST_WAIT_TIME		75	//time in MS
#define MENU_SCROLL_FAST_HOLD_COUNT		4	//number of times before fast scrolling starts

//Button input
#define OPEN_MENU_BUTTON_HOLD 			BUTTON_A
#define OPEN_MENU_BUTTON_PRESS 			DPAD_DOWN
//Menu controls
#define BUTTON_CONFIRM					BUTTON_A
#define BUTTON_BACK						BUTTON_B
#define BUTTON_UP						DPAD_UP
#define BUTTON_DOWN						DPAD_DOWN
#define BUTTON_LEFT						DPAD_LEFT
#define BUTTON_RIGHT					DPAD_RIGHT

// Keyboard input
#define KB_OPEN_MENU_KEY 				KEY_F3
//Menu controls
#define KB_BUTTON_CONFIRM				KEY_NUMPAD_5
#define KB_BUTTON_BACK					KEY_NUMPAD_0
#define KB_BUTTON_UP					KEY_NUMPAD_8
#define KB_BUTTON_DOWN					KEY_NUMPAD_2
#define KB_BUTTON_LEFT					KEY_NUMPAD_4
#define KB_BUTTON_RIGHT					KEY_NUMPAD_6

#pragma endregion //}

// User Menu Settings
#pragma region User Menu Settings //{

//#define NDEBUG
//#define DEVKIT
//#define PRIVATE

#pragma endregion //}
