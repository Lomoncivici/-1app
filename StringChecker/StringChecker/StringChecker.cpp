#include "pch.h"
#include <windows.h>
#include <cstring>

extern "C" __declspec(dllexport) bool __stdcall CheckCharacters(const char* str, const char* chars) {
    while (*chars) {
        if (strchr(str, *chars) == NULL) {
            return false;
        }
        chars++;
    }
    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}