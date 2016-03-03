#include "quakedef.h"

#ifdef _DEBUG
#include <stdio.h>
#endif

int32_t com_argc = 1;
char* com_argv[MAX_NUM_ARGVS + 1];

void COM_ParseCmdLine(int32_t argc, char** argv)
{
	com_argv[0] = "";

	for (com_argc = 1; com_argc < argc && com_argc < (MAX_NUM_ARGVS + 1); ++com_argc)
	{
		if (argv[com_argc])
		{
			com_argv[com_argc] = argv[com_argc];
		}
	}
}

#ifdef _WIN32
void COM_ParseCmdLineWin32(uint8_t *lpCmdLine)
{
	com_argv[0] = "";

	while (*lpCmdLine && (com_argc < MAX_NUM_ARGVS + 1))
	{
		while (*lpCmdLine && ((*lpCmdLine <= 32) || (*lpCmdLine > 126)))
		{
			lpCmdLine++;
		}
		
		if (*lpCmdLine)
		{
			com_argv[com_argc] = lpCmdLine;
			com_argc++;

			while (*lpCmdLine && ((*lpCmdLine > 32) && (*lpCmdLine <= 126)))
			{
				lpCmdLine++;
			}

			if (*lpCmdLine)
			{
				*lpCmdLine = 0;
				lpCmdLine++;
			}
		}
	}
}
#endif

int32_t COM_CheckParm(char* parm)
{
	for (int32_t i = 1; i < com_argc; ++i)
	{
		if (!Q_strcmp(parm, com_argv[i]))
		{
			return i;
		}
	}

	return 0;
}