#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

DWORD pID;
DWORD liveValue = 0x1DF8F91BF04;


float live;
float nLive = live += 300;

int main() {
    std::cout << "Health : PRESS F8" << std::endl;

    while (true) {
        if (GetAsyncKeyState(0x77)) { //0x77 == VK_F8
            for (;;) {
                HWND hwnd = FindWindowA(0, ("Horizon Zero Dawn: Complete Edition"));

                if (!hwnd)
                system("Color 04");
                    std::cerr << "Unable to find the game" << std::endl;

                GetWindowThreadProcessId(hwnd, &pID);
                HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);

                if (!pHandle)
                system("Color 04");
                    std::cerr << "Error Detected : Unresolvable Memory Address. " << std::endl;

                ReadProcessMemory(pHandle, (LPVOID)liveValue, &live, (DWORD)sizeof(live), 0);
                system("Color 0B");
                std::cout << "Current HP (Memory Address) : " << &live << std::endl;
                std::cout << "Current HP : " << live << std::endl;

                WriteProcessMemory(pHandle, (LPVOID)liveValue, &nLive, (DWORD)sizeof(nLive), 0);
                std::cout << "Modified HP (Memory Address) : " << &nLive << std::endl;
                std::cout << "Modified HP : " << nLive << std::endl;
            }
        }
    }
}