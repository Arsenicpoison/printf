#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: the format
 * @fn: the associated function
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: the format
 * @fmt_t: the associated function
 */

typedef struct fmt fmt_t;

/**
 * struct specifier - struct specifier
 * @valid: the valid character.
 * @f: the functions associated.
 *
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, 
int print_c(va_list args);
int print_string(va_list args);
int _putchar(char c);
int print_percent(va_list args);
int (*specify(char x))(va_list args);

#endif
