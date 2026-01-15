#include <windows.h>
#include <iostream>
#include <chrono>

int main()
{
    const int screenWidth = 120;
    const int screenHeight = 40;

    HANDLE hConsole = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    SetConsoleActiveScreenBuffer(hConsole);

    CHAR_INFO* screen = new CHAR_INFO[screenWidth * screenHeight];

    auto tp1 = std::chrono::system_clock::now();

    while (true)
    {
        auto tp2 = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed = tp2 - tp1;
        tp1 = tp2;

        float deltaTime = elapsed.count();

        // Clear
        for (int i = 0; i < screenWidth * screenHeight; i++)
        {
            screen[i].Char.UnicodeChar = L' ';
            screen[i].Attributes = 0;
        }

        // Example: draw a moving point
        static float x = 0;
        x += 10.0f * deltaTime;
        int sx = (int)x % screenWidth;
        int sy = screenHeight / 2;

        screen[sy * screenWidth + sx].Char.UnicodeChar = L'@';
        screen[sy * screenWidth + sx].Attributes = FOREGROUND_GREEN;

        WriteConsoleOutput(
            hConsole,
            screen,
            { (short)screenWidth, (short)screenHeight },
            { 0, 0 },
            new SMALL_RECT{ 0,0,(short)(screenWidth - 1),(short)(screenHeight - 1) }
        );
    }
}
