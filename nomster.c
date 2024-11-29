#include <Windows.h>

HHOOK kHook;

LRESULT __stdcall kCallback(int nCode, WPARAM wParam, LPARAM lParam) {
	PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT)lParam;

	if (wParam == WM_KEYDOWN && nCode == HC_ACTION) {
		INPUT input = { INPUT_KEYBOARD, {0, 0, 0, 0, (ULONG_PTR) NULL} };
		switch (key->vkCode) {
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