#include "main.h"

unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);

/**
 * print_width - store leading spaces to a buffer for modifier width .
 * @output: the buffer_t struct containing a character array.
 * @printed: The current number of characters  printed to output
 *           for a  number specifier.
 * @flags: flag modifiers.
 * @wid:  width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_string_width -  store leading spaces to a buffer for modifier width.
 * @output: A buffer_t struct containing a character array.
 * @flags: flag modifiers.
 * @wid: width modifier.
 * @prec: precision modifier.
 * @size: size of the string.
 * Return: number of bytes stored to the buffer.
 */
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - store trailing spaces to a buffer for '-' flag.
 * @output: buffer_t struct containing a character array.
 * @printed: The current number of bytes stored to output
 *           for a specifier.
 * @flags: flag modifiers.
 * @wid: width modifier.
 *
 * Return: number of bytes stored to the buffer.
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
