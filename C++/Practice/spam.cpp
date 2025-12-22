#include <windows.h>
#include <iostream>

int main()
{
    std::cout << "Autoclicker started. Press Ctrl+C to stop." << std::endl;

    // Small delay to give you time to focus the game window
    Sleep(3000);

    while (true)
    {
        // Prepare the key press event
        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.wVk = 'R'; // Virtual key code for 'R'
        ip.ki.wScan = 0;
        ip.ki.dwFlags = 0; // 0 for key press
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        SendInput(1, &ip, sizeof(INPUT));

        // Key release event
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

        Sleep(500); // wait 500ms before next press
    }

    return 0;
}
