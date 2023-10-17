#include "main.h"

/**
 *handle_print- prints an input string with arguments.
 *@fmt:formated string
 *@list:list of arguments
 *@ind:the ind
 *@buffer:buffer array for handling print
 *@flags:calculates active flags
 *@width:the width
 *@precision:precision specifier
 *@size:size specifier
 *Return:return 1 or 2
 */
int handle_print(const char *fmt, int *ind, va_list list,char buffer[],
int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;

	fmt_t fmt_types[] = {{'c', print_char}, {'s', print_string},
		{'%', print_percent},
		{'i', print_int}, {'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer},
		{'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string},
		{'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width,
				precision, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
	unknow_len += write(1,"%%", 1);
	if(fmt[*ind -1] == '\0')
		unknow_len += write(1, " ", 1);
	else if (width)
		{
		--(*ind);
			while (fmt[*ind] != '\0' && fmt[*ind] != '%')
			--(*ind);
			if (fmt[*ind] == '\0')
			--(*ind);
			return (1);
			}
		unknow_len += write(1, &fmt[*ind],1);
		return (unknow_len);
		}	
	return (printed_chars);
}
