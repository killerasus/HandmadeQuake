#pragma once

#include "quakedef.h"

/**
 * Copies a string from source to destiny
 * @param[in] dest	Destination string
 * @param[in] src	Source string
 */
void Q_strcpy(char* dest, const char* src);

/**
 * Copies a string from source to destiny by count bytes
 * @param[in] dest	Destination string
 * @param[in] src	Source string
 * @param[in] count	Number of bytes to copy
 */
void Q_strncpy(char* dest, const char* src, int32_t count);

/**
* Implements the strcmp
*
* @param[in] s1	Left hand string
* @param[in] s2	Right hand string
* @return	-1 if LHS comes first, 0 if equal, 1 if RHS comes first
*/
int32_t Q_strcmp(const char* s1, const char* s2);

/**
* Takes a string in decimal or hexadecimal form and converts to integer
*
* @param str	String (ex: "54", "-12", "0x4321fd", "-0x4bdc")
* @return	Integer representation of the string passed
*/
int32_t Q_atoi(const char* str);
