#include "pch.h"
#include <Minhook.h>
#include <Windows.h>
#include <cstdio>
#include <cstdint>
#include "hooks.h"

void init()
{

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    MH_Initialize();
}


void main()
{
    init();
    printf("Paint The Town Red by Buck3ts41\n");
    printf("V.1.1.2\n\n");
    HookMainShit();

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)

{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}