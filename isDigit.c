#include "main.h"

/**
 *is_digit - checks if a character is a digit
 *@c:test character
 *Return:returns 1 if c is a digit else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
