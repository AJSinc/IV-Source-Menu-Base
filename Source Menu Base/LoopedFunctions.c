/**
 *	Looped functions.
 *	Functions that will continuously be
 *	called, mainly for  bools etc
 */

#include "Globals.h"

void LoopedFunctions()
{

}

//Online session only
void LoopedNetworkFunctions()
{
	
	float gameChatTextPosY = 0.85;
	for(int i = 0; i < MAX_NETWORK_PLAYERS; i++)
	{
		if(!NetworkIsPlayerActive(i))
		{
			continue;
		}
		if(GetPlayerIndex() == i) continue;
		if(!PLAYER_HAS_CHAR(i)) continue;
		if(!DOES_CHAR_EXIST(GetPlayerPed(i))) continue;
		//functions here
		
	}
	
}