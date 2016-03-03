#include "quakedef.h"

#ifdef _WIN32
int32_t CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32_t nCmdShow )
#else
int32_t main (int32_t argc, char** argv)
#endif
{
#ifdef _WIN32
	COM_ParseCmdLineWin32(lpCmdLine);
#else
	COM_ParseCmdLine(argc, argv);
#endif

	int32_t test = COM_CheckParm("-setalpha");
	int32_t value = Q_atoi(com_argv[test + 1]);

    return 0;
}
