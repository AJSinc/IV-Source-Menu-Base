/**
 *	
 *  
 *
 */

#include "Menu.h"

#pragma region Menu Settings //{

uint LoadGXTSetting(char* gxtEntry, char* gxtStringSetting)
{
	uint currentPos = 0;
	char* wholeEntryString = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	char* currentSetting = "";
	if(strlen(wholeEntryString) <= 0) return 0;
	
	
	while(indexOfAfterIndex(wholeEntryString, ':', currentPos) != -1 && currentPos < strlen(wholeEntryString))
	{
		if(stricmp(gxtStringSetting, substring(wholeEntryString, currentPos, indexOfAfterIndex(wholeEntryString, ':', currentPos))) == 0)
		{
			char* settingValue = "";
			uint result = 0;
			uint startIndex = indexOfAfterIndex(wholeEntryString, ':', currentPos) + 1;
			uint endIndex = (indexOfAfterIndex(wholeEntryString, '?', currentPos) == -1) ? strlen(wholeEntryString) : indexOfAfterIndex(wholeEntryString, '?', currentPos);
			settingValue = substring(wholeEntryString, startIndex, endIndex);
			if(STRING_TO_INT(settingValue, &result))
			{
				return result;
			}
			else if(stricmp(settingValue, "true") == 0 || stricmp(settingValue, "on") == 0) //true/on
			{
				return true;
			}
			return 0;
		}
		else
		{
			if(indexOfAfterIndex(wholeEntryString, '?', currentPos) != -1)
			{
				currentPos = indexOfAfterIndex(wholeEntryString, '?', currentPos) + 1;
			}
			else
			{
				return 0;
			}
		}	
	}
	return 0;
}

uint LoadGXTCustomSetting(char* gxtEntry, char* gxtStringSetting, char* compareString, uint resultTrue, uint resultFalse)
{
	uint currentPos = 0;
	char* wholeEntryString = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	char* currentSetting = "";
	if(strlen(wholeEntryString) <= 0) return resultFalse;
	
	while(indexOfAfterIndex(wholeEntryString, ':', currentPos) != -1 && currentPos < strlen(wholeEntryString))
	{
		if(stricmp(gxtStringSetting, substring(wholeEntryString, currentPos, indexOfAfterIndex(wholeEntryString, ':', currentPos))) == 0)
		{
			char* settingValue = "";
			uint result = 0;
			uint startIndex = indexOfAfterIndex(wholeEntryString, ':', currentPos) + 1;
			uint endIndex = (indexOfAfterIndex(wholeEntryString, '?', currentPos) == -1) ? strlen(wholeEntryString) : indexOfAfterIndex(wholeEntryString, '?', currentPos);
			settingValue = substring(wholeEntryString, startIndex, endIndex);
			if(stricmp(settingValue, compareString))
			{
				return resultTrue;
			}
			return resultFalse;
		}
		else
		{
			if(indexOfAfterIndex(wholeEntryString, '?', currentPos) != -1)
			{
				currentPos = indexOfAfterIndex(wholeEntryString, '?', currentPos) + 1;
			}
			else
			{
				return resultFalse;
			}
		}
	}
	return resultFalse;
}

bool LoadSettingBool(char* gxtEntry, int index, uint stat, int bitIndex)
{
	char* gxtPtr = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	int* gxtPtrIdx = (int*)((int)gxtPtr + (index << 2));
	bool value = false;
	if(!IS_NETWORK_SESSION())
	{
		int statVal = GET_INT_STAT(stat);
		value = GetBit(statVal, bitIndex);
		if(gxtPtr != NULL)
		{
			SetBit(*gxtPtrIdx, bitIndex, value);
		}
	}
	else if(gxtPtr != NULL)
	{
		printf("addr:%x val: %d", (uint)gxtPtrIdx, *gxtPtrIdx);
		value = GetBit(*gxtPtrIdx, bitIndex);
	}
	return value;
}

byte LoadSettingByte(char* gxtEntry, int index, uint stat, int byteIndex)
{
	char* gxtPtr = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	int* gxtPtrIdx = (int*)((int)gxtPtr + (index << 2));
	byte value = 0;
	if(!IS_NETWORK_SESSION())
	{
		int statVal = GET_INT_STAT(stat);
		value = GetByteSet(statVal, byteIndex);
		if(gxtPtr != NULL)
		{
			SetByteSet(*gxtPtrIdx, byteIndex, value);
		}
	}
	else if(gxtPtr != NULL)
	{
		value = GetByteSet(*gxtPtrIdx, byteIndex);
	}
	return value;
}

int LoadSettingInt(char* gxtEntry, int index, uint stat)
{
	char* gxtPtr = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	int* gxtPtrIdx = (int*)((int)gxtPtr + (index << 2));
	int value = 0;
	if(!IS_NETWORK_SESSION())
	{
		value = GET_INT_STAT(stat);
		if(gxtPtr != NULL)
		{
			*gxtPtrIdx = value;
		}
	}
	else if(gxtPtr != NULL)
	{
		value = *gxtPtrIdx;
	}
	return value;
}

void SaveSettingBool(char* gxtEntry, int index, uint stat, int bitIndex, bool value)
{
	char* gxtPtr = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	int* gxtPtrIdx = (int*)((int)gxtPtr + (index << 2));
	uint statVal = GET_INT_STAT(stat);
	SetBit(statVal, bitIndex, value);
	SET_INT_STAT(stat, statVal);
	if(gxtPtr != NULL)
	{
		SetBit(*gxtPtrIdx, bitIndex, value);
	}
}

void SaveSettingByte(char* gxtEntry, int index, uint stat, int byteIndex, byte value)
{
	char* gxtPtr = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	int* gxtPtrIdx = (int*)((int)gxtPtr + (index << 2));
	uint statVal = GET_INT_STAT(stat);
	SetByteSet(statVal, byteIndex, value);
	SET_INT_STAT(stat, statVal);
	if(gxtPtr != NULL)
	{
		SetByteSet(*gxtPtrIdx, byteIndex, value);
	}
}

void SaveSettingInt(char* gxtEntry, int index, uint stat, int value)
{
	char* gxtPtr = GET_STRING_FROM_TEXT_FILE(gxtEntry);
	int* gxtPtrIdx = (int*)((int)gxtPtr + (index << 2));
	SET_INT_STAT(stat, value);
	if(gxtPtr != NULL)
	{
		*gxtPtrIdx = value;
	}
}

#pragma endregion //}