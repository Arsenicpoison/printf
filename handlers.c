#include "main.h"

unsigned char handle_flags(const char *flag, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int int, unsigned char);

/**
 * handle_flags - matches flags with corresponding values
 * @flag: a pointer to a potential string of flags
 * @index: an index counter for the original format string
 * Return: if flags characters are matched, a corresponding value
 * otherwise 0
 */

unsigned char handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}
	return (ret);
}

/**
 * handle_length - matches length modifiers with corresponding values
 * @flag: a pointer to a potential length modifier
 * @index: an index counter for the original format string
 * Return: if a length modifier is matched, a corresponding value
 * otherwise 0
 */

unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}
	return (0);
}

/**
 * handle_length - matches width modifiers with corresponding values
 * @args: a va_list of arguments
 * @index: an index counter for the original format string
 * Return: if a width modifier is matched, a corresponding value
 * otherwise 0
 */

int handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}

/**
 * handle_length - matche a precision modifier with its corresponding value
 * @args: a va_list argumnet
 * @modifier: a pointer to a potential precision modifier
 * @index: an index counter for the original format string
 * Return: if a precision modifier is matched, its value
 * if the precision modifier is empty, zero or negative 0
 * otherwise -1
 */

int handle_precision(va_list args, const char *modofier, char *index)
{
	int value = 0;

	if (modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') && *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}
	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}

/**
 * handle_specifiers - matches a conversion specifier with
 * a corresponding conversion function
 * @specifier: a pointer to a potential conversion specifier
 * Return: if conversion function is matched, a pointer
 * otherwise, NULL
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converter[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
