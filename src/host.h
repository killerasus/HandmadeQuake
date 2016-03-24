#pragma once

#include "common.h"

/**
 * Initializes
 */
void Host_Init(void);

/**
 * Filters the time passed
 *
 * @returns true if time is valid
 */
qboolean Host_FilterTime(float time);

/**
 *
 */
void Host_Frame(float);

/**
 *
 */
void Host_Shutdown(void);