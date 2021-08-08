#include "BaseWindow.h"

// Global pointer
BaseWindow* pBaseWindow = NULL;

BaseWindow::BaseWindow()
{
}

BaseWindow::~BaseWindow()
{
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_CREATE:
	{
		// Event fired when window is created
		pBaseWindow->onCreate();
	}
	break;


	case WM_DESTROY:
	{
		// Event fired when window destroyed
		pBaseWindow->onDestroy();
		PostQuitMessage(0);
	}
	break;


	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}


	return NULL;
}

bool BaseWindow::init()
{
	const auto pClassName = L"My Class Name";

	//Window class structure
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.hInstance = NULL;
	wc.style = CS_OWNDC;              // Device context to be rendered independently
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;                // To allocate extra bytes in the class structure
	wc.cbWndExtra = 0;                // To allocate extra bytes for every window created off of this class
	wc.hIcon = NULL;
	wc.hbrBackground = NULL;          // Don´t let Windows draw it, we will use DirectX
	wc.hCursor = NULL;                // Default cursor
	wc.lpszMenuName = NULL;           // No menu
	wc.hIconSm = NULL;
	wc.lpszClassName = pClassName;

	// Register window class
	if (!RegisterClassEx(&wc))
		return false;

	// Returns a handle to the window
	m_hWnd = CreateWindowEx(
		0,
		pClassName,
		L"My Window Name Place Holder",
		WS_OVERLAPPEDWINDOW,
		200, 200, 1024, 720,
		NULL, NULL, hInstance, NULL);

	if (!m_hWnd)
		return false;

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	if (!pBaseWindow)
	{
		pBaseWindow = this;
	}

	return true;
}

bool BaseWindow::broadcast()
{
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	pBaseWindow->onUpdate();

	return true;
}

bool BaseWindow::release()
{
	// Destroy the window
	if (!DestroyWindow(m_hWnd))
		return false;

	return true;
}

bool BaseWindow::isRunning()
{
	return true;
}

void BaseWindow::onCreate()
{
}

void BaseWindow::onUpdate()
{
}

void BaseWindow::onDestroy()
{
}
