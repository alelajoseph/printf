#include "main.h"

/**
 *is_printable -identify the character to print
 *@c:char to be tested
 *Return:returns 1 on sucess else 1
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
