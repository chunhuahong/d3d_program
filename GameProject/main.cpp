#include <Windows.h>
#include <Windowsx.h>

#define WINDOW_CLASS L"UGPDX"
#define WINDOW_TITLE L"Demo Window"

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYUP:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE prevhInst, LPSTR cmdLine, int show) {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MsgProc;
	wc.hInstance = hInst;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = (LPCWSTR)WINDOW_CLASS;

	RegisterClassEx(&wc);
	HWND hWnd = CreateWindowEx(NULL, WINDOW_CLASS, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, 300, 400, 600, 800, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, show);
	UpdateWindow(hWnd);

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

		}
	}
	UnregisterClass(WINDOW_CLASS, hInst);
	return 0;
}