#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void _putchar_c(char c)
{
	write(1, &c, 1);
}

void _putchar(va_list a)
{
	char c;

	c = va_arg(a, int);
	write(1, &c, 1);
}

void print_str(va_list a)
{
	char *c;

	c = va_arg(a, char *);
	while (*c != '\0')
	{
		_putchar_c(*c++);
	}
}

void print_int()
{
	
}


/**
 * _printf - prints output according to a format.
 * @format: input string.
 * Return: int, number of characters printed,
 */

int _printf(const char *format, ...)
{
	va_list a;
	int i, j, count;

	cs_t cspec[] = {
		{'c', _putchar},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int}
	};

	if (format == NULL)
		return (0);

	i = j = count = 0;
	va_start(a, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 4)
			{
				if (format[i + 1] == cspec[j].cs &&
				    format[i + 1] != '%')
				{
					cspec[j].f(a);
					i++;
				}
				j++;
			}
			i++;
			_putchar_c(format[i]);
		}
		else
			_putchar_c(format[i]);
		count++;
		i++;

	}
	return (count);
}
