#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int _putchar(char c);

int print_char(va_list args);
int _printf(const char *format, ...);
int print_string(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_uint(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);

int print_hexCaps(va_list args);
#endif

