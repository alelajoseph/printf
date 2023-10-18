#include "main.h"

/**
 *convert_size_number - converts a number to the specified size.
 *@num:input number
 *@size:indicates the type to be casted
 *Return:returns value of num casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 *convert_size_unsgnd - casts an input number to the specified size
 *@num:casted number
 *@size:indicates the type to be casted
 *Return:returns the value of num casted.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
