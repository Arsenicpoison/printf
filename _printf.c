#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Output a formatted string
 * @format: Character string to print
 * * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0;
	unsigned int tmp = 0;
	unsigned int n;

	va_start(args, format);
	for (; format[count] != '\0'; count++)
	{
		if (format[count] != '%')
		{
			putchar(format[count]);
		}
		else if (format[count + 1] == 's')
		{
			n = test_string(va_arg(args, int));
			count++;
			tmp = (n - 1);
		}
		else if (format[count + 1] == 'c')
		{
			putchar(va_arg(args, int));
			count++;
		}
		else if (format[count + 1] == '%')
		{
			putchar('%');
		}
		tmp = tmp + 1;
	}
	return (tmp);
}
