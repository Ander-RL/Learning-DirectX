#pragma once
#include <Windows.h>



class BaseWindow
{
public:

	BaseWindow();
	~BaseWindow();

	// Initialize the window
	bool init();
	bool broadcast();
	// Release the window
	bool release();
	bool isRunning();

	// Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();

protected:

	HWND m_hWnd;
	bool m_isRunning;

};

