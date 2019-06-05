/**	Globals
 * The menu itself (with default settings) takes up 70 global variables. 
 * 
 * Put your own global variables below.
 */

#include "Globals.h"

void InitMenu()
{
	
	//Player Option
	/*
	godMode = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_GOD_MODE);
	playerInvisibility = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_INVIS);
	autoAim = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_AUTOAIM);
	neverWanted = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_NEVER_WANTED);
	playerSuperRun = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_SUPER_RUN);
	playerSuperJump = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_SUPER_JUMP);
	gravityOff = LoadSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, PLAYER_GRAVITY);
	*/
	//godMode = LoadGXTSetting("SOURCE_MENU", "GODEMODE");
	//playerInvisibility = LoadGXTSetting("SOURCE_MENU", "PLAYER_INVIS");
	//autoAim = LoadGXTSetting("SOURCE_MENU", "AUTO_AIM");
	//neverWanted = LoadGXTSetting("SOURCE_MENU", "NEVER_WANTED");
	//playerSuperRun = LoadGXTSetting("SOURCE_MENU", "SUPER_RUN");
	//playerSuperJump = LoadGXTSetting("SOURCE_MENU", "SUPER_JUMP");
	//gravityOff = LoadGXTSetting("SOURCE_MENU", "GRAVITY_OFF");
	walkOnWaterBitSet = 0;
	SetBit(walkOnWaterBitSet, GetPlayerIndex(), LoadGXTSetting("SOURCE_MENU", "WALK_ON_WATER"));
	forceFieldBitSet = 0;
	SetBit(forceFieldBitSet, GetPlayerIndex(), LoadGXTSetting("SOURCE_MENU", "FORCEFIELD"));
	
	//Network Players
	selectedNetworkPlayerIndex = 0;
	restrictWeaponBitSet = 0;
	restrictVehicleBitSet = 0;
	SET(walkOnWaterObject, MAX_NETWORK_PLAYERS, INVALID_HANDLE);

	//Vehicle Option
	vehicleHelper = LoadGXTSetting("SOURCE_MENU", "VHELPER");
	vehicleInvisibility = LoadGXTSetting("SOURCE_MENU", "VEH_INVIS");
	vehicleSpeedBoost = LoadGXTSetting("SOURCE_MENU", "VEH_SPEEDBOOST");
	vehicleJump = LoadGXTSetting("SOURCE_MENU", "VEH_JUMP");
	vehicleGrounded = LoadGXTSetting("SOURCE_MENU", "VEH_GROUNDED");
	driveThroughWalls = LoadGXTSetting("SOURCE_MENU", "VEH_WALLS");
	
	//Object options
	selectedEntity = INVALID_HANDLE;
	
	//Weapon Options
	unlimitedAmmo = LoadGXTSetting("SOURCE_MENU", "UNLIMITED_AMMO");
	juggernautBitSet = 0;
	SetBit(juggernautBitSet, GetPlayerIndex(), LoadGXTSetting("SOURCE_MENU", "JUGGERNAUT"));
	
	//Ped/Bodyguard Options
	SET(bodyguard, MAX_BODYGUARDS, INVALID_HANDLE);
	
	//Weather/Time Options
	freezeWeather = LoadGXTSetting("SOURCE_MENU", "FREEZE_WEATHER");
	freezeTime = LoadGXTSetting("SOURCE_MENU", "FREEZE_TIME");
	
	//Other Options
	ambientPlanes = LoadGXTSetting("SOURCE_MENU", "AMBIENT_PLANES");
	gameChat = false; //LoadGXTSetting("SOURCE_MENU", "GAME_CHAT");
	flymod = LoadGXTSetting("SOURCE_MENU", "FLYMOD");
	scriptedCam = INVALID_HANDLE;
	scriptedCamPitch = 0.0;
	scriptedCamYaw = 0.0;
	
	//Auto-Aim
	DISABLE_PLAYER_LOCKON(GetPlayerIndex(), !autoAim);
	ALLOW_LOCKON_TO_FRIENDLY_PLAYERS(GetPlayerIndex(), autoAim);
	ALLOW_LOCKON_TO_RANDOM_PEDS(GetPlayerIndex(), autoAim);
	
	//Turn Gravity Off
	SET_GRAVITY_OFF(gravityOff);
	//Ambient Planes
	SWITCH_AMBIENT_PLANES(ambientPlanes);
	
}

void SaveMenuSettings()
{
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 0, godMode);
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 1, playerInvisibility);
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 2, autoAim);
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 3, neverWanted);
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 4, playerSuperRun);
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 5, playerSuperJump);
	SaveSettingBool("SOURCE_MENU", 0, PLAYER_E_STAT, 6, gravityOff);
	print("Settings Saved");
	printf("Stat: %d", GET_INT_STAT(PLAYER_E_STAT));
}
