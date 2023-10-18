#include "main.h"

/**
 *append_hexa_code - appending ASCII in hexacode to buffer
 *@buffer:array of characters
 *@i:appending index
 *@ascii_code:ASCII code
 *Return:Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "012345678ABCDEF";

	if(ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
