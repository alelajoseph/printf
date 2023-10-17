#include "main.h"

/**
 *print_char - outputs a character.
 *@types:group of arguments
 *@buffer:beffer array for handling print.
 *@flags:displays or calculates active flages.
 *@width:show the width
 *@precision:specifications to precision
 *@size:displays size
 *
 * Return:returns number of characters printed.
 */
int print_char(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 *print_string - prints a string
 *@types:group of arguments
 *@buffer:beffer array for handling print.
 *@flags:displays or calculates active flages.
 *@width:show the width
 *@precision:specifications to precision
 *@size:displays size
 *
 * Return:returns number of characters printed. *
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int len, i; /*len refers to length */

	len = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
		str = " ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
	}
	return (write(1, str, len));
}

/**
 *print_percent - prints a percentage sign
 *@types:group of arguments
 *@buffer:beffer array for handling print.
 *@flags:displays or calculates active flages.
 *@width:show the width
 *@precision:specifications to precision
 *@size:displays size
 *
 * Return:returns number of characters printed. *
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size)
		return (write(1, "%%", 1));
}
