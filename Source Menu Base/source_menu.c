/**
 * Source Menu
 *
**/

#include "Menu/Menu.h"
#include "Globals.h"

void main()
{
	THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
	WAIT(500);
	ResetMenu();
	InitMenu();
	bool inNetwork = IS_NETWORK_SESSION();
	while(true)
	{
		WAIT(0);
		
		if(GetMenuFlag(MENU_ENABLED))
		{
			
			if(!GetMenuFlag(DISABLE_DISPLAY))
				MenuDisplay();
			
			if(!GetMenuFlag(DISABLE_INPUT))
				MenuInput();
			
			if(!GetMenuFlag(DISABLE_LOOPED_SETUP))
			{
				if(GetMenuFlag(USE_LOOPED_SETUP_AS_SETUP))
				{
					InitMenuSetup();
					ResetMenuItems();
				}
				LoopedSetup();
			}
			
		}
		else if(IsActivateMenuInput()) ActivateMenu();
		
		if(!GetMenuFlag(DISABLE_LOOPED_FUNCTIONS))
			LoopedFunctions();
		
		if(inNetwork)
		{//Online session only
			if(!GetMenuFlag(DISABLE_LOOPED_NETWORK))
				LoopedNetworkFunctions();
		}
	}
}
