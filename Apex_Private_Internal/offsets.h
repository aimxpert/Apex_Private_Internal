#pragma once
#include <iostream>
#include <Windows.h>
namespace OffsetsT1 {
	DWORD Entity = 0x1FF4D88; //cl_entitylist0x0216f7b0 
	DWORD LocalPlayer = 0x24CC258;
	DWORD ViewRender = 0x77BA3B0;
	DWORD viewAngles = 0x25b4 - 0x14;
	DWORD in_duck = 0x77BA6C0;
	DWORD PunchAngle = 0x24B8;
	DWORD lastVisableTime = 0x1a10; //m_hudInfo_visibilityTestAlwaysPasses + 0x3
	DWORD OFF_GLOW_ENABLE = 0x28c;                       //Script_Highlight_GetCurrentContext
	DWORD OFF_GLOW_THROUGH_WALL = 0x26c;                 //Script_Highlight_SetVisibilityType
	DWORD OFF_GLOW_FIX = 0x270;
	DWORD OFF_GLOW_HIGHLIGHT_ID = 0x298;                 //[DT_HighlightSettings].m_highlightServerActiveStates    
	DWORD OFF_GLOW_HIGHLIGHTS = 0xB2330C0;      //HighlightSettings

	DWORD showfps_enabled = 0x01983b00;
	DWORD Bones = 0xDA8 + 0x48;
	DWORD m_grapple = 0x2d28;
	DWORD shadow_enable = 0x017f1b30;
	DWORD CPlayer_camera_origin = 0x1f60;
	DWORD ViewModule = 0x2e00;
	DWORD IN_JUMP = 0x77BA5D8;
	DWORD TimeBase = 0x2108;
	DWORD m_traversalProgress = 0x2BE4;
	DWORD m_traversalStartTime = 0x2BE8;
	DWORD ss_viewmodelfov = 0x0237fd70;
	DWORD m_iObserverMode = 0x34a4;//idk
	DWORD m_xp = 0x382c;
	DWORD m_iSignifierName = 0x0478;
	DWORD m_ModelName = 0x0030;
	DWORD NameList = 0xd48e5e0;
	DWORD ViewMatrix = 0x11a350;
	DWORD M_VecAbsOrigin = 0x017c;
	DWORD m_Health = 0x0328;
	DWORD m_Shield = 0x01a0;
	DWORD m_MaxShield = 0x01a4;
	DWORD m_Shield_type = 0x47cc;
	DWORD m_lastUCmdSimulationTicks = 0x1c54;//idk
	DWORD m_lastUCmdSimulationRemainderTime = 0x1c58;//idk
}

template<typename T = uintptr_t, typename A>
T& read(A address) {
	auto addresss = (DWORD64)address;
	if (addresss > 0x40000 && (addresss + sizeof(T)) < 0x7FFFFFFF0000)
		return *(T*)addresss;

	auto n = nullptr;
	return reinterpret_cast<T&>(n);
}

template <typename T>
void write(uintptr_t address, T data) {
	if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000)
		*(T*)(address) = data;
}