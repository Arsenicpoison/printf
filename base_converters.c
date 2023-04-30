#include "main.h"

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output, unsigned long int num,
		char *base, unsigned char flags, int wid, int prec);

/**
 * convert_sbase - converts a signed long to an inputted base and
 * store the result to a buffer contained in a struct
 * @output: a buffer_t struct containing a char array
 * @num: a signed long to be converted
 * @base: a pointer to a string containing the base to convert to
 * @flags: flag modifiers
 * @wid: a width modifier
 * @prec: a precision modifier
 * Return: the number of bytes stored to the buffer.
 */

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit;
	char pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;
	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wid--) /*Handle precision*/
			ret += _memcpy(output, &pad, 1);
		if (NEG_FLAG == 0) /*Handle width*/
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
	}
	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}

/**
 * convert_ubase - converts an unsigned long to an inputted base and
 * stores the result to a buffer contained in a struct
 * @output: buffer_t struct containing a character array
 * @num: an unsigned long to be converted
 * @base: a pointer to a string containing the base to convert to
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * Return:the number of bytes stored to the buffer
 */

unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int size;
	unsigned int ret = 1;
	char digit;
	char pad = '0';
	char *lead = "0x";

	for (size = 0; *(base + size);)
		size++;
	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		if (((flags >> 5) & 1) == 1) /*Handle precision*/
			ret += _memcpy(output, &pad, 1);
		if (NEG_FLAG == 0) /*Handle width*/
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1) /*Print 0x for ptr address*/
			ret += _memcpy(output, lead, 2);
	}
	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
