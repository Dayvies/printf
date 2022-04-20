<hi>Printf</h1>
<strong>Description</strong>
int printf(const char *format, ...) sends formatted output to stdout.

<strong>int printf(const char *format, ...)</strong>
format − This is the string that contains the text to be written to stdout. It can optionally contain embedded format tags that are replaced by the values specified in subsequent additional arguments and formatted as requested. Format tags prototype is %[flags][width][.precision][length]specifier

c- Character
d or i - Signed decimal integer
e - Scientific notation (mantissa/exponent) using e character	
E - Scientific notation (mantissa/exponent) using E character
f - Decimal floating point
g - Uses the shorter of %e or %f
G - Uses the shorter of %E or %f
o - Signed octal
s - String of characters
u - Unsigned decimal integer
x - Unsigned hexadecimal integer
X - Unsigned hexadecimal integer (capital letters)
p - Pointer address
n - Nothing printed
% - Percentage

<strong>Flags </strong>
' ' -  If no sign is going to be written, a blank space is inserted before the value.
0   - Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier).
-   - Left-justify within the given field width; Right justification is the default (see width sub-specifier).
'#'   - Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed.

<strong>Return Value</strong>

If successful, the total number of characters written is returned. On failure, a negative number is returned
