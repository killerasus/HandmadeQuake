#pragma once

#include <stdint.h>

#ifdef _WIN32
#include "winquake.h"
#endif

#define MAX_NUM_ARGVS 50

typedef enum { false, true } qboolean;

extern int32_t com_argc;
extern char* com_argv[MAX_NUM_ARGVS+1];

/**
 * Parses the command line for parameters
 *
 * @param[in] argc Number or parameters
 * @param[in] argv Array of parameter strings
 */
void COM_ParseCmdLine(int32_t argc, char **argv);

#ifdef _WIN32
/**
 * Parses the command line for parameters
 * 
 * @param[in] lpCmdLine	Command line parameters
 */
void COM_ParseCmdLineWin32(uint8_t *lpCmdLine);
#endif

/**
* Checks for a parameter in largv
*
* @param parm	Parameter to check for
* @returns	Index to parameter position in largv, 0 if non-existent
*/
int32_t COM_CheckParm(char* parm);