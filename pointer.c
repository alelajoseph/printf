#include "main.h"

/**
 *print_pointer - handles pointer variables
 *@types:List of arguments
 *@buffer:buffer array for handling print
 *@flags:calculates active flags.
 *@width:get width
 *@precision:specifications of precision
 *@size:The size specifier.
 *Return:returns number of characters printed.
 */

int print_pointer(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	char extra_c = 0, padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil), 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F _ZERO) && !(flags & F _MINUS))
		padd = '0';
	if (flags & F _PLUS)
		extra_c = '+', length++;
	else if (flags & F _SPACE)
		extra_c = '', length++;
	ind++;
	return (write_pointer(buffer, ind, length, width, flags, padd, extra_c,
padd_star));
}
