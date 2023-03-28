#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: format string containing directives
 *
 * Return: number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					count += write(1, (char *) &va_arg(args, int), 1);
					break;
				case 's':
					count += write(1, va_arg(args, char *), _strlen(va_arg(args, char *)));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of s
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s++))
	{
		len++;
	}
	return (len);
}
