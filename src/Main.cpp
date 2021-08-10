#include "Window.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	try {
		Window window(1024, 720, L"Ventana prueba");

		// Run the message loop.

		MSG msg = { };
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return 0;
	}
	catch (const BaseException& e)
	{
		MessageBox(NULL, (LPWSTR)e.what(), (LPWSTR)e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(NULL, (LPWSTR)e.what(), L"Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(NULL, L"No details available", L"Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}



























//#ifndef UNICODE
//#define UNICODE
//#endif


//#include "CustomWin.h"
//#include <sstream>
//
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
//{
//	const auto pClassName = L"My Class Name";
//
//	// Window class
//	WNDCLASSEX wc = { 0 };
//	wc.cbSize = sizeof(wc);
//	wc.hInstance = hInstance;
//	wc.style = CS_OWNDC;      // Device context to be rendered independently
//	wc.lpfnWndProc = WindowProc;
//	wc.cbClsExtra = 0;             // To allocate extra bytes in the class structure
//	wc.cbWndExtra = 0;             // To allocate extra bytes for every window created off of this class
//	wc.hIcon = NULL;
//	wc.hbrBackground = NULL;          // Don´t let Windows draw it, we will use DirectX
//	wc.hCursor = NULL;          // Default cursor
//	wc.lpszMenuName = NULL;          // No menu
//	wc.hIconSm = NULL;
//	wc.lpszClassName = pClassName;
//
//	// Register window class
//	RegisterClassEx(&wc);
//
//	// Returns a handle to the window
//	HWND hWnd = CreateWindowEx(
//		0,
//		pClassName,
//		L"My Window Name Place Holder",
//		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
//		200, 200, 640, 480,
//		NULL, NULL, hInstance, NULL);
//
//	ShowWindow(hWnd, SW_SHOW);
//
//	// Run the message loop.
//
//	MSG msg = { };
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//
//	return 0;
//}
//
//LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	case WM_KEYDOWN:
//		if (wParam == 'F')
//		{
//			SetWindowText(hWnd, L"Title changed!");
//			OutputDebugStringW(L"Pulsando F\n");
//		}
//		if (wParam == 'G')
//		{
//			SetWindowText(hWnd, L"Title changed again!");
//		}
//		break;
//
//	case WM_CHAR:
//	{
//		OutputDebugStringW(L"CHARs being pressed\n");
//	}
//	break;
//
//	case WM_LBUTTONDOWN:
//	{
//		POINTS pt = MAKEPOINTS(lParam);
//		std::ostringstream oss;
//		oss << "(" << pt.x << "," << pt.y << ")\n";
//		OutputDebugStringA(oss.str().c_str()); // 'A' to avoid unicode problems
//	}
//	break;
//	}
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}