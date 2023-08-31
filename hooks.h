#pragma once

#include "offsets.h"

void(__fastcall* PTTRPlayer_Power___ctor_Orig)(DWORD*, DWORD*, int32_t*, float*, float*, float*, float*, bool*, bool*, DWORD*);
bool(__fastcall* Enemy__EnemyAttackPlayer_Orig)(DWORD*, float*, float*, bool*, uint8_t*, DWORD*, DWORD*);
bool(__fastcall* Enemy__BulletHitPlayer_Orig)(DWORD*, DWORD*, DWORD*);
bool(__fastcall* Enemy__DoKnockdown_Orig)(DWORD*, DWORD*, DWORD*, bool*, DWORD*);
bool(__fastcall* CheatsManager__get_UnlimitedAmmo_Orig)(DWORD*);
bool(__fastcall* CheatsManager__get_WeakEnemies_Orig)(DWORD*);
bool(__fastcall* Bullet__CheckForCollisions_Orig)(DWORD*, DWORD*);

bool __stdcall Enemy__EnemyAttackPlayer_Hook(DWORD* __this, float* attackDamage, float* attackRange, bool* targetIsPlayer, uint8_t* checkMask, DWORD* forceWeapon, DWORD* method)
{
    return false;
}

bool __stdcall Enemy__BulletHitPlayer_Hook(DWORD* __this, DWORD* player, DWORD* method)
{
    return false;
}

bool __stdcall Enemy__DoKnockdown_Hook(DWORD* __this, DWORD* applyForce, DWORD* forceAtPosition, bool* fromClient, DWORD* method)
{
    return true;
}

bool __stdcall CheatsManager__get_UnlimitedAmmo_Hook(DWORD* method)
{
    return true;
}

bool __stdcall CheatsManager__get_WeakEnemies_Hook(DWORD* method)
{
    return true;
}

bool __stdcall Bullet__CheckForCollisions_Hook(DWORD* __this, DWORD* method)
{
    return false;
}

void HookMainShit()
{

    // Crea il hook utilizzando MinHook
    MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + EnemyAttack), &Enemy__EnemyAttackPlayer_Hook, (LPVOID*)Enemy__EnemyAttackPlayer_Orig);
    MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + BulletHit), &Enemy__BulletHitPlayer_Hook, (LPVOID*)Enemy__BulletHitPlayer_Orig);
    MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + AlwaysKnockdown), &Enemy__DoKnockdown_Hook, (LPVOID*)Enemy__DoKnockdown_Orig);
    MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + InfiniteAmmo), &CheatsManager__get_UnlimitedAmmo_Hook, (LPVOID*)CheatsManager__get_UnlimitedAmmo_Orig);
    MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + WeakEnemies), &CheatsManager__get_WeakEnemies_Hook, (LPVOID*)CheatsManager__get_WeakEnemies_Orig);
    MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + NoBulletCollision), &Bullet__CheckForCollisions_Hook, (LPVOID*)Bullet__CheckForCollisions_Orig);
    // Abilita il hook
    printf(" [*] No Player hit -> F1\n ");
    printf("[*] No Player BulletHit -> F2\n ");
    printf("[*] Always Knockdown -> F3\n");
    printf(" [*] Infinite Ammo -> F4\n");
    printf(" [*] Damage Multiplier -> F5\n");
    printf(" [*] No Bullet Collisions -> F6\n\n");

    while (true)
    {
        if (GetAsyncKeyState(VK_F1) & 0x8000)
        {
            MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + EnemyAttack));
            printf(" [!] No Player Hit ON\n");
            Sleep(150);

        }
        if (GetAsyncKeyState(VK_F2) & 0x8000)
        {
            MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + BulletHit));
            printf(" [!] No Bullet Hit ON\n");
            Sleep(150);

        }
        if (GetAsyncKeyState(VK_F3) & 0x8000)
        {
            MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + AlwaysKnockdown));
            printf(" [!] Always KnockDown ON\n");
            Sleep(150);

        }
        if (GetAsyncKeyState(VK_F4) & 0x8000)
        {
            MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + InfiniteAmmo));
            printf(" [!] Infinite Ammo ON\n");
            Sleep(150);

        }
        if (GetAsyncKeyState(VK_F5) & 0x8000)
        {
            MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + WeakEnemies));
            printf(" [!] Damage Multiplier ON\n");
            Sleep(150);

        }
        if (GetAsyncKeyState(VK_F6) & 0x8000)
        {
            MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + NoBulletCollision));
            printf(" [!] No Bullet Collision ON\n");
            Sleep(150);
        }
    }
    

    
}