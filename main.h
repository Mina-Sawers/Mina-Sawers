#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int print_char(int c);
int print_digit(long n, int base);
int print_str(char *s);
int print_format(char specifier, va_list ap);
int _printf(const char *format, ...);

#endif
