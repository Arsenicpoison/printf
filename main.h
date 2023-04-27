#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct specifier - struct specifier
 * @id: type char pointer of the specifier
 * @valid: the valid char
 * @f: the functions associated.
 *
 */
typedef struct specifier
{
        char *valid;
        int (*f)(va_list);
} spec;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i);
int print_c(va_list args);
int print_string(va_list args);
int _putchar(char c);
int print_percent(va_list args);
int (*specify(char x))(va_list args);
int print_int(va_list args);
int print_dec(va_list args);

#endif
