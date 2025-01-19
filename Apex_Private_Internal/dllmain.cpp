#include <Windows.h>
#include <iostream>
#include "Menu.hpp"


void CreateConsole()
{

	if (!AllocConsole()) {
		return;
	}

	FILE* fDummy;
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	std::cout.clear();
	std::clog.clear();
	std::cerr.clear();
	std::cin.clear();

	HANDLE hConOut = CreateFile(("CONOUT$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE hConIn = CreateFile(("CONIN$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
	SetStdHandle(STD_ERROR_HANDLE, hConOut);
	SetStdHandle(STD_INPUT_HANDLE, hConIn);
	std::wcout.clear();
	std::wclog.clear();
	std::wcerr.clear();
	std::wcin.clear();
}

extern HWND window;
LPCSTR window_class_name = "Apex Legends";

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	window = FindWindowA(0, window_class_name);

	//CreateConsole();
	//std::cout << "[eSafe.Prv] Init" << std::endl;
	//createhooks();
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

uintptr_t GameBase;

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		if (GameBase = (uintptr_t)(GetModuleHandleA)(("r5apex.exe")))
		{
			DisableThreadLibraryCalls(hMod);
			CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		}
		else {
			kiero::shutdown();
			exit(0);
		}
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}

