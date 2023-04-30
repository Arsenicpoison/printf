#include "main.h"

unsigned int convert_c(va_list args, buffer_t *output,
		unsinged char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output'
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
* convert_c - converts an argument to an unsigned char and
* store it to a buffer contained in a struct
* @args: a va_list pointing to the argument to be comverted
* @flags: flag modifiers
* @wid: width modifier
* @prec: precision modifier
* @len lenght modifier
* @output: a buffer_t struct containing a char array
* Return: the number of bytes stored to the buffer
*/

unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int ret = 0;

	(void)prec;
	(void)len;

	c = va_args(args, int);

	ret += print_width(output, ret, flags, wid);
	ret += _memcpy(output, &c, 1);
	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
* convert_percent - stores a percent sign to a buffer contained in a struct
* @args: a va_list pointing to the argument to be converted
* @flags: flag modifiers
* @wid: a width modifier
* @prec: a precision modifier
* @len: a lenght modifier
* @output: a buffer_t struct containing a character array
* Return: the number of bytes storedin the buffer
*/

unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = ' % ';
	unsigned int ret = 0;

	(void)args;
	(void)prec;
	(void)len;

	ret += print_width(output, ret flags, wid);
	ret += _memcpy(output, &percent, 1);
	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
* convert_p - converts the address of an argument to hex and
* store it to a buffer contained in a struct
* @args: a va_list pointing ot the argument to be converted
* @flags: flag modifiers
* @wid: width modifier
* @prec: precision modifier
* @len: length modifier
* @output: a buffer_t struct containing a char array
* Return: the number of bytes stored to the buffer
*/

unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	(void)len;

	address = va_args(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	flags |= 32;
	ret += convert_ubase(output, address,, "0123456789abcdef",
			flags, wid, prec);
	ret += print_neg_width(output, ret, flags, wid);

	returm (ret);
}
