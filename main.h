#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int _putchar(char c);
int buffchar(char *buffer, int length);

int print_char(va_list args, char *buffer, int *arrlength);
int _printf(const char *format, ...);
int print_string(va_list args, char *buffer, int *arrlength);
int print_int(va_list args, char *buffer, int *arrlength);
int print_binary(va_list args, char *buffer, int *arrlength);
int print_uint(va_list args, char *buffer, int *arrlength);
int print_octal(va_list args, char *buffer, int *arrlength);
int print_hex(va_list args, char *buffer, int *arrlength);
int buff_push(char *buff, char c, int *arrlength);

int print_hexCaps(va_list args, char *buffer, int *arrlength);
#endif
