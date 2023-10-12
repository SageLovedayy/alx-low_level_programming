#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
* print_char - prints anything of specified types
* @value: char value
* @seperator: seperator
*/
void print_char(char value, const char *seperator)
{
	printf("%s%c", seperator, value);
}

/**
* print_integer - prints integer
* @value: integer value
* @seperator: seperator
*/
void print_integer(int value, const char *seperator)
{
	printf("%s%d", seperator, value);
}

/**
* print_float - prints float
* @value: float value
* @seperator: seperator
*/
void print_float(float value, const char *seperator)
{
	printf("%s%f", seperator, value);
}

/**
* print_string - prints char
* @value: string value
* @seperator: seperator
*/
void print_string(char *value, const char *seperator)
{
	if (value == NULL)
	{
		printf("%s(nil)", seperator);
	}
	else
	{
		printf("%s%s", seperator, value);
	}
}

/**
* print_all - prints anything of specified types
* @format: list of types of arguments (c, i, f and s)
*/
void print_all(const char *format, ...)
{


	const char *ptr = format;
	char *seperator = "";

	va_list ap;

	va_start(ap, format);

	while (*ptr != '\0')
	{
		if (*ptr == 'c')
		{
			print_char(va_arg(ap, int), seperator);
		}
		else if (*ptr == 'i')
		{
			print_integer(va_arg(ap, int), seperator);
		}
		else if (*ptr == 'f')
		{
			print_float(va_arg(ap, double), seperator);
		}
		else if (*ptr == 's')
		{
			print_string(va_arg(ap, char *), seperator);
		}

		seperator = ", ";
		ptr++;
	}

	va_end(ap);
	printf("\n");
}
