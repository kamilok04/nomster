#include <Windows.h>
#include <iostream>

HHOOK kHook;

LRESULT __stdcall kCallback(int nCode, WPARAM wParam, LPARAM lParam) {
	PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT)lParam;
	bool shiftHeld = false;

	if (wParam == WM_KEYDOWN && nCode == HC_ACTION) {
		INPUT input = { INPUT_KEYBOARD, {0, 0, 0, 0, NULL} };
		switch (key->vkCode) {
		case VK_SHIFT:
			shiftHeld = true;
			break;

		case 'N':
		case 'n':
			input.ki.wVk = 'M';
			SendInput(1, &input, sizeof(INPUT));
			return 1;

		case 'M':
		case 'm':
			input.ki.wVk = 'N';
			SendInput(1, &input, sizeof(INPUT));
			return 1;
		}
	}


	if (wParam == WM_KEYUP && nCode == HC_ACTION) {
		switch (key->vkCode) {
		case VK_SHIFT:
			shiftHeld = false;
			break;
		}
	}
	return CallNextHookEx(NULL, 0, wParam, lParam);

}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HHOOK kHook = SetWindowsHookEx(WH_KEYBOARD_LL, kCallback, hInstance, 0);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (kHook != NULL)
		UnhookWindowsHookEx(kHook);
	return 0;
}