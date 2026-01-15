#include <windows.h>
#include <cmath>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_KEYDOWN:
        PostQuitMessage(0);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    const wchar_t CLASS_NAME[] = L"HeartWindow";

    WNDCLASSW wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Heart Test",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        400, 300,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, SW_SHOW);

    HDC hdc = GetDC(hwnd);

    // Draw heart
    for (float y = 1.3f; y > -1.3f; y -= 0.02f)
    {
        for (float x = -1.3f; x < 1.3f; x += 0.02f)
        {
            float a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0.0f)
            {
                int sx = int((x + 1.3f) / 2.6f * 400);
                int sy = int((1.3f - y) / 2.6f * 300);
                SetPixel(hdc, sx, sy, RGB(255, 0, 0));
            }
        }
    }

    ReleaseDC(hwnd, hdc);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
