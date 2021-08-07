#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	const auto pClassName = L"My Class Name";

	// Window class
	WNDCLASSEX wc = {0};
	wc.cbSize        = sizeof(wc);
	wc.hInstance     = hInstance;
	wc.style         = CS_OWNDC;      // Device context to be rendered independently
	wc.lpfnWndProc   = WindowProc;
	wc.cbClsExtra    = 0;             // To allocate extra bytes in the class structure
	wc.cbWndExtra    = 0;             // To allocate extra bytes for every window created off of this class
	wc.hIcon         = NULL;
	wc.hbrBackground = NULL;          // Don´t let Windows draw it, we will use DirectX
	wc.hCursor       = NULL;          // Default cursor
	wc.lpszMenuName  = NULL;          // No menu
	wc.hIconSm       = NULL;
	wc.lpszClassName = pClassName;

	// Register window class
	RegisterClassEx(&wc);

	// Returns a handle to the window
	HWND hWnd = CreateWindowEx(
		0, 
		pClassName, 
		L"My Window Name Place Holder", 
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 
		200, 200, 640, 480, 
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);

	// Run the message loop.

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	/*case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);



		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	return 0;*/

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}