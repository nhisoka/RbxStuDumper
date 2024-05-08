#include <windows.h>
#include <iostream>
#include <thread>

#include "Scanner.hpp"

int main()
{
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>(stdin), ("CONOUT$"), ("w"), stdout);
    freopen_s(reinterpret_cast<FILE**>(stdin), ("CONIN$"), ("r"), stdin);

    const auto pScanner{ Scanner::get_singleton() };

    const auto pseudo2addr = pScanner->scan("41 B9 EE D8 FF FF 4C 8B C1 41 3B D1 0F 84 88 00 00 00 81 FA EF D8 FF FF 74 45 81 FA F0 D8 FF FF 74 32 48 8B 41 ? 44 2B CA 48 8B 48 ? 4C 8B 01 41 0F B6 40 ? 44 3B C8 7F 12 41 8D 41 ? 48 98 48 83 C0 ? 48 C1 E0 ? 49 03 C0 C3 48 8D 05 ? ? ? ? C3 48 8B 41 ? 48 05 ? ? ? ? C3 48 8B 41 ? 48 8B 51 ? 48 3B 41 40 75 06 48 8B 41 ? EB 0B 48 8B 40 ? 48 8B 08 48 8B 41 ? 48 89 82 ? ? ? ? C7 82 ? ? ? ? ? ? ? ? 49 8B 40 ? 48 05 ? ? ? ? C3 49 8B 40 ? 48 8B 49 ? 48 89 81 ? ? ? ? C7 81 ? ? ? ? ? ? ? ? 49 8B 40 ? 48 05 ? ? ? ? C3");

    const auto luau_execute = pScanner->scan("80 79 06 00 0F 85 ? ? ? ? E9 ? ? ? ?");

    const auto freeblock = pScanner->scan("4C 8B 51 ? 49 83 E8 ? 44 8B CA 4C 8B D9 49 8B 10 48 83 7A 28 00 75 22 83 7A 30 00 7D 1C 49 63 C1 49 8D 0C C2 49 8B 44 C2 ? 48 89 42 ? 48 85 C0 74 03 48 89 10 48 89 51 ? 48 8B 42 ? 49 89 00 83 6A ? ? 4C 89 42 ? 75 4B 48 8B 4A ? 48 85 C9 74 06 48 8B 02 48 89 01 48 8B 0A 48 85 C9 74 0A 48 8B 42 ? 48 89 41 ? EB 17 41 0F B6 C1 49 39 54 C2 60 49 8D 0C C2 75 08 48 8B 42 ? 48 89 41 ? 49 8B 43 ? 45 33 C9 4C 63 42 ? 48 8B 48 ? 48 FF 60 ? C3");

    const auto luaC_step = pScanner->scan("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 59 ? B8 ? ? ? ? 0F B6 F2 0F 29 74 24 ? 4C 8B F1 44 8B 43 ? 44 0F AF 43 ? 48 8B 6B ? 48 2B 6B ? 41 F7 E8 8B FA C1 FF ? 8B C7 C1 E8 ? 03 F8 48 8B 83 ? ? ? ? 48 85 C0 74 04 33 D2 FF D0 0F B6 43 ? 84 C0 75 32 E8 ? ? ? ? 0F B6 43 ? F2 0F 11 83 ? ? ? ? 84 C0 75 1D E8 ? ? ? ? F2 0F 11 83 ? ? ? ? F2 0F 5C 83 ? ? ? ? F2 0F 11 83 ? ? ? ? E8 ? ? ? ? 44 0F B6 7B ? 49 8B CE 48 63 D7 0F 28 F0 E8 ? ? ? ? 48 8B F8 E8 ? ? ? ? 0F 28 C8 41 8B D7 F2 0F 5C CE 45 85 FF 0F 84 99 00 00 ? 83 EA ? 74 60 83 EA ? 74 5B 83 EA ? 74 41 83 FA 01 0F 85 87 00 00 00 48 01 BB ? ? ? ? 0F 28 C1 F2 0F 58 83 ? ? ? ? F2 0F 11 83 ? ? ? ? 40 84 F6 0F 84 82 00 00 ? 0F 28 C1 F2 0F 58 83 ? ? ? ? F2 0F 11 83 ? ? ? ? EB 54 0F 28 C1 F2 0F 58 83 ? ? ? ? F2 0F 11 83 ? ? ? ? EB 3A 48 01 BB ? ? ? ? 0F 28 C1 F2 0F 58 83 ? ? ? ? F2 0F 11 83 ? ? ? ? 40 84 F6 74 39 0F 28 C1 F2 0F 58 83 ? ? ? ? F2 0F 11 83 ? ? ? ? EB 0B 80 7B 21 01 74 CD 40 84 F6 74 19 F2 0F 58 8B ? ? ? ? 48 01 BB ? ? ? ? F2 0F 11 8B ? ? ? ? EB 17 F2 0F 58 8B ? ? ? ? 48 01 BB ? ? ? ? F2 0F 11 8B ? ? ? ? 48 63 4B ? 33 D2 48 6B C7 ? 48 F7 F1 80 7B 21 00 48 8B 4B ? 48 8B F8 0F 85 45 01 00 00 F2 0F 10 93 ? ? ? ? 48 B8 15 AE 47 E1 7A 14 AE 47 4C 63 43 ? 0F 28 CA F2 0F 5C 8B ? ? ? ? F2 0F 10 05 ? ? ? ? 48 F7 E1 48 2B CA 48 D1 E9 48 03 CA 48 C1 E9 ? 4C 0F AF C1 66 0F 2F C1 76 08 49 8B C0 E9 CD 00 00 00 4C 8B 8B ? ? ? ? 0F 57 C0 49 8B C9 48 2B 8B ? ? ? ? 78 07 F2 48 0F 2A C1 EB 15 48 8B C1 83 E1 ? 48 D1 E8 48 0B C1 F2 48 0F 2A C0 F2 0F 58 C0 8B 83 ? ? ? ? 4C 2B 8B ? ? ? ? 83 E0 ? F2 0F 5C 93 ? ? ? ? F2 0F 5E C1 49 C1 E9 ? 8B 8C 83 ? ? ? ? 44 89 8C 83 ? ? ? ? 41 8B C1 FF 83 ? ? ? ? 2B C1 01 83 ? ? ? ? 49 8B C8 66 41 0F 6E C9 F2 0F 59 C2 F3 0F E6 C9 F2 48 0F 2C D0 F2 0F 59 0D ? ? ? ? 66 0F 6E 83 ? ? ? ? F3 0F E6 C0 F2 0F 59 05 ? ? ? ? F2 0F 58 C8 F2 0F 59 0D ? ? ? ? F2 48 0F 2C C1 48 2B C8 48 8B 43 ? 48 2B CA 48 3B C8 7C 0A 49 3B C8 48 8B C1 49 0F 4F C0 48 89 43 ? 4C 89 83 ? ? ? ? E8 ? ? ? ? 48 8B 43 ? 48 8B CB 48 89 83 ? ? ? ? F2 0F 11 83 ? ? ? ? E8 ? ? ? ? EB 13 48 03 C1 48 89 43 ? 48 3B C5 72 07 48 2B C5 48 89 43 ? 48 8B 83 ? ? ? ? 48 85 C0 74 08 41 8B D7 49 8B CE FF D0 48 8B 5C 24 ? 48 8B C7 48 8B 6C 24 ? 48 8B 74 24 ? 0F 28 74 24 ? 48 83 C4 ? 41 5F 41 5E 5F C3");

    const auto lua_newthread = pScanner->scan("48 89 5C 24 ? 57 48 83 EC ? 48 8B 51 ? 48 8B D9 48 8B 42 ? 48 39 42 48 72 07 B2 ? E8 ? ? ? ? F6 43 01 04 74 0F 4C 8D 43 ? 48 8B D3 48 8B CB E8 ? ? ? ? 48 8B CB E8 ? ? ? ? 48 8B 4B ? 48 8B F8 48 89 01 C7 41 ? ? ? ? ? 48 83 43 08 ? 48 8B 4B ? 48 8B 81 ? ? ? ? 48 85 C0 74 08 48 8B D7 48 8B CB FF D0 48 8B 5C 24 ? 48 8B C7 48 83 C4 ? 5F C3");

    const auto luaE_newthread = pScanner->scan("48 89 5C 24 ? 57 48 83 EC ? 44 0F B6 41 ? BA ? ? ? ? 48 8B F9 E8 ? ? ? ? 48 8B 57 ? 48 8B D8 44 0F B6 42 ? C6 00 ? 41 80 E0 ? 44 88 40 ? 0F B6 57 ? 88 50 ? 48 8B D7 48 8B 4F ? 48 89 48 ? 33 C0 89 43 ? 48 8B CB 48 89 43 ? 48 89 43 ? 48 89 43 ? 48 89 43 ? 48 89 43 ? 48 89 43 ? 48 89 43 ? 48 89 43 ? 48 89 43 ? 0F B6 47 ? 88 43 ? E8 ? ? ? ? 48 8B 47 ? 48 89 43 ? 0F B6 47 ? 88 43 ? 48 8B C3 48 8B 5C 24 ? 48 83 C4 ? 5F C3");

    const auto fireproximityprompt = pScanner->scan("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4C 8B F9 E8 ? ? ? ? 48 8B F8 48 85 C0 0F 84 ? ? ? ? 48 8B 50 10 48 85 D2 0F 84 ? ? ? ? 8B 42 08 85 C0 0F 84 ? ? ? ? 0F 1F 84 00 ? ? ? ? 8D 48 01 F0 0F B1 4A ? 74 0A 85 C0 0F 84 ? ? ? ? EB EC 4C 8B 6F 08 48 8B 7F 10 4C 89 6D 17 48 89 7D 1F 0F 57 C0 F3 0F 7F 45 ? 48 85 FF 74 04 F0 FF 47 08 4C 89 6D 97 48 89 7D 9F 4C 8D 45 97 49 8B D7 48 8B 0D ? ? ? ? E8 ? ? ? ? 0F 57 C0 F3 0F 7F 45 ? 48 85 FF 74 04 F0 FF 47 08 48 8D 45 A7 48 89 45 6F 48 C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? 4C 89 6D E7 48 89 7D EF F3 0F 7F 45 ? 4C 8D 4D 07 4C 8D 45 E7 49 8B D7 48 8B 0D ? ? ? ? E8 ? ? ? ? 90 41 BC ? ? ? ? 48 8B 5D AF 48 85 DB 74 2B 41 8B C4 F0 0F C1 43 ? 83 F8 01 75 1E 48 8B 03 48 8B CB FF 10 41 8B C4 F0 0F C1 43 ? 83 F8 01 75 09 48 8B 03 48 8B CB FF 50 08 4D 85 FF 0F 84 ? ? ? ? 49 8B 77 60 48 85 F6 74 13 48 8B 4E 60 48 85 C9 74 0D E8 ? ? ? ? 48 8B F0 EB 03 49 8B F7 48 85 F6 0F 84 ? ? ? ? 48 8B 5E 18 E8 ? ? ? ? 0F B7 93 ? ? ? ? 0F B7 88 ? ? ? ? 2B D1 0F B7 80 ? ? ? ? 3B D0 77 7D 48 8B CE E8 ? ? ? ? 4C 8B C8 48 85 C0 74 6D 48 8D 45 B7 48 89 45 6F 0F 57 C0 F3 0F 7F 45 ? 48 85 FF 74 04 F0 FF 47 08 4C 89 6D B7 48 89 7D BF 49 8B 57 10 48 85 D2 0F 84 ? ? ? ? 8B 42 08 85 C0 0F 84 ? ? ? ? 8D 48 01 F0 0F B1 4A ? 74 0A 85 C0 0F 84 ? ? ? ? EB EC 49 8B 47 08 49 8B 4F 10 48 89 45 F7 48 89 4D FF 4C 8D 45 B7 48 8D 55 F7 49 8B C9 E8 ? ? ? ? 80 3D ? ? ? ? ? 0F 84 ? ? ? ? E8 ? ? ? ? 33 D2 F7 35 ? ? ? ? 85 D2 0F 85 ? ? ? ? 48 C7 45 ? ? ? ? ? 48 C7 45 ? ? ? ? ? 48 C7 45 ? ? ? ? ? 88 55 C7 8D 4A 20 E8 ? ? ? ? 48 C7 45 ? ? ? ? ? 48 C7 45 ? ? ? ? ? 0F 10 05 ? ? ? ? 0F 11 00 F2 0F 10 0D ? ? ? ? F2 0F 11 48 ? 0F B6 0D ? ? ? ? 88 48 18 C6 40 19 00 48 89 45 C7 45 33 C0 41 8D 50 01 48 8D 4D C7 E8 ? ? ? ? 90 48 8B 55 DF 48 83 FA 10 72 35 48 FF C2 48 8B 4D C7 48 8B C1 48 81 FA ? ? ? ? 72 1C 48 83 C2 27 48 8B 49 F8 48 2B C1 48 83 C0 F8 48 83 F8 1F 76 07 FF 15 ? ? ? ?");

    const auto pushinstance = pScanner->scan("48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4C 8B E1 BA ? ? ? ? E8 ? ? ? ? 48 8B F8 48 89 45 ? 48 8B C8 E8 ? ? ? ? 48 8B D8 49 8B CC E8 ? ? ? ? 4C 8B F8 48 8B CB E8 ? ? ? ? 48 8B D8 41 BD FF FF FF FF 48 85 C0 74 72 48 8B 00 48 8B CB FF 50 ? 84 C0 74 65 48 8B 03 45 8D 45 ? 48 8D 55 ? 48 8B CB FF 10 48 8B C8 48 8B 30 48 8B 40 ? 48 85 C0 74 08 F0 FF 40 ? 48 8B 41 ? 48 89 75 ? 48 89 45 ? 48 8B 5D ? 48 85 DB 74 39 41 8B C5 F0 0F C1 43 ? 83 F8 01 75 28 48 8B 03 48 8B CB FF 10 41 8B C5 F0 0F C1 43 ? 83 F8 01 75 13 48 8B 03 48 8B CB FF 50 ? EB 08 0F 57 C9 F3 0F 7F 4D ? 48 8B 75 ? 48 85 F6 0F 84 95 04 00 ? 45 33 F6 4D 85 E4");

    const auto rFromLuaState = pScanner->scan("48 89 5C 24 ? 55 56 57 48 83 EC ? 48 8B FA 48 8B E9 8B 0D ? ? ? ? E8 ? ? ? ? 8B D8 89 44 24 ? 48 85 ED 74 4A 48 8B CD E8 ? ? ? ? 48 8B F0 B9 ? ? ? ? E8 ? ? ? ? 48 89 44 24 ? 48 85 C0 74 10 48 8B D6 48 8B C8 E8 ? ? ? ? 48 8B F0 EB 02 33 F6 48 8B CD E8 ? ? ? ? 48 89 46 ? 48 8B D6 48 8B CF E8 ? ? ? ? EB 2B 48 85 FF 74 26 48 8B CF E8 ? ? ? ? 48 8B F8 48 85 C0 74 16 48 8B C8 E8 ? ? ? ? BA ? ? ? ? 48 8B CF E8 ? ? ? ? 90 8B CB E8 ? ? ? ? 90 48 8B 5C 24 ? 48 83 C4 ? 5F 5E 5D C3");

    const auto luaD_rawunprotected = pScanner->scan("48 89 4C 24 ? 48 83 EC ? 48 8B C2 49 8B D0 FF D0 33 C0 EB 04");

    const auto taskdefer = pScanner->scan("48 8B C4 48 89 58 08 55 56 57 41 56 41 57 48 83 EC 40 48 8B E9 33 FF 48 89 78 18 4C 8D 48 18 4C 8D 05 ? ? ? ? 33 D2 E8 ? ? ? ? 44 8B F0 48 8B CD E8 ? ? ? ? 48 8B D8 40 32 F6 44 8D 7F 01 40 38 35 ? ? ? ? 75 12 40 38 35 ? ? ? ? 75 09 40 38 35 ? ? ? ? 74 1F");

    std::cout << std::hex << "Pseudo2addr: 0x" << pseudo2addr << std::endl;

    std::cout << std::hex << "luau_execute: 0x" << luau_execute << std::endl;

    std::cout << std::hex << "freeblock: 0x" << freeblock << std::endl;

    std::cout << std::hex << "luaC_step: 0x" << luaC_step << std::endl;

    std::cout << std::hex << "lua_newthread: 0x" << lua_newthread << std::endl;

    std::cout << std::hex << "luaE_newthread: 0x" << luaE_newthread << std::endl;

    std::cout << std::hex << "fireproximityprompt: 0x" << fireproximityprompt << std::endl;

    std::cout << std::hex << "pushinstance: 0x" << pushinstance << std::endl;

    std::cout << std::hex << "rFromLuaState: 0x" << rFromLuaState << std::endl;

    std::cout << std::hex << "luaD_rawunprotected: 0x" << luaD_rawunprotected << std::endl;

    std::cout << std::hex << "RBX::ScriptContext::defer: 0x" << taskdefer << std::endl;


}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL, // handle to DLL module
    const DWORD fdwReason, // reason for calling function
    const LPVOID lpvReserved) // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        std::thread(main).detach();
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != nullptr) {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }
    return TRUE;
}
