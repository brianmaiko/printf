#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - produces output according to a format.
 * @format: A string containing zero or more directives
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
				count += _putchar(va_arg(args, int));
				break;

				case 's':
				count += _print_str(va_arg(args, char *));
				break;

				case '%':
				count += _putchar('%');
				break;

				default:
				count += _putchar('%');
				count += _putchar(format[i]);
				break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
/**
 * _print_str - prints a string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int _print_str(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
