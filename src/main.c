#include "quakedef.h"

static BOOL IsRunning = TRUE;

static double GTimePassed = 0;
static double SecondsPerTick = 0;
static __int64 GTimeCount = 0;

float Sys_InitFloatTime(void)
{
	LARGE_INTEGER Frequency;
	QueryPerformanceFrequency(&Frequency);

	SecondsPerTick = 1.0 / (double)Frequency.QuadPart;

	LARGE_INTEGER Counter;
	QueryPerformanceCounter(&Counter);

	GTimeCount = Counter.QuadPart;

	return 0;
}

float Sys_FloatTime(void)
{
	LARGE_INTEGER Counter;
	QueryPerformanceCounter(&Counter);

	__int64 Interval = Counter.QuadPart - GTimeCount;
	GTimeCount = Counter.QuadPart;

	double SecondsGoneBy = (double)Interval * SecondsPerTick;
	GTimePassed += SecondsGoneBy;

	return (float)GTimePassed;
}


void Sys_Shutdown(void)
{
	IsRunning = FALSE;
}


LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;

	// catch any relevant messages here
	switch (uMsg)
	{
	case WM_ACTIVATE:
		break;

	case WM_CREATE:
		break;

	case WM_DESTROY:
		Sys_Shutdown();
		break;
	default:
		Result = DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return Result;
}

#ifdef _WIN32
int32_t CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32_t nCmdShow)
#else
int32_t main(int32_t argc, char** argv)
#endif
{
#ifdef _WIN32
		COM_ParseCmdLineWin32(lpCmdLine);
#else
		COM_ParseCmdLine(argc, argv);
#endif
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = MainWndProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = "Module 2";

	if (!RegisterClass(&wc))
		exit(EXIT_FAILURE);

	HWND mainwindow;
	DWORD WindowStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;

	RECT r;
	r.top = r.left = 0;
	r.right = 800;
	r.bottom = 600;

	AdjustWindowRect(&r, WindowStyle, FALSE);

	mainwindow = CreateWindowEx(
		0,
		"Module 2",
		"Lesson 2.6",
		WindowStyle,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		r.right - r.left,
		r.bottom - r.top,
		NULL,
		NULL,
		hInstance,
		0);

	ShowWindow(mainwindow, SW_SHOWDEFAULT);

	HDC DeviceContext = GetDC(mainwindow);
	PatBlt(DeviceContext, 0, 0, 800, 600, BLACKNESS);
	ReleaseDC(mainwindow, DeviceContext);

	Host_Init();

	float oldtime = Sys_InitFloatTime();

	MSG msg;
	while (IsRunning)
	{
		// Check in with OS
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		float newtime = Sys_FloatTime();
		Host_FilterTime(newtime);
	}

	Host_Shutdown();

	return 0;
}