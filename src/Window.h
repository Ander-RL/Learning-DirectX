#pragma once

#include <sstream>
#include "CustomWin.h"
#include "BaseException.h"

class Window
{
public:
	class Exception : public BaseException
	{
	public:
		Exception(int line, const char* file, HRESULT hr) noexcept; // HRESULT is part of windows errors
		const char* what() const noexcept override;
		virtual const char* GetType() const noexcept;
		static std::string TranslateErrorCode(HRESULT hr) noexcept; // Takes windows errors and gives description
		HRESULT GetErrorCode() const noexcept; // hr getter
		std::string GetErrorString() const noexcept;
	private:
		HRESULT hr;
	};

private:
	// singleton manages registration/cleanup of window class
	class WindowClass // inner class
	{
	public:
		static LPCWSTR GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr LPCWSTR wndClassName = L"Custom Direct3D Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};


public:
	Window(int width, int height, LPCWSTR name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

private:
	int width;
	int height;
	HWND hWnd;
};