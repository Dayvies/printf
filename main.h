#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int _putchar(char c);
int buffchar(char *buffer, int length);
/**
 * typedef unsigned long int ul - unsigned long int
 */
typedef unsigned long int ul;

int print_char(va_list args, char *buffer, int *arrlength, ul *arr);
int _printf(const char *format, ...);
int print_string(va_list args, char *buffer, int *arrlength, ul *arr);
int print_int(va_list args, char *buffer, int *arrlength, ul *arr);
int print_binary(va_list args, char *buffer, int *arrlength);
int print_uint(va_list args, char *buffer, int *arrlength, ul *arr);
int print_octal(va_list args, char *buffer, int *arrlength, ul *arr);
int print_hex(va_list args, char *buffer, int *arrlength, ul *arr);
int buff_push(char *buff, char c, int *arrlength);
int print_String(va_list args, char *buffer, int *arrlength);
int print_address(va_list args, char *buffer, int *arrlength, ul *arr);
int get_flag(const char *f, ul *arr, int i);

int print_hexCaps(va_list args, char *buffer, int *arrlength, ul *arr);
void print_rev(va_list args, char *buffer, int *arrlength);
void print_rot13(va_list args, char *buffer, int *arrlength);
#endif
