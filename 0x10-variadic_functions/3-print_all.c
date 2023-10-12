#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
* print_all - prints anything of specified types
* @format: list of types of arguments (c, i, f and s)
*/
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *seperator = "";

	va_list ap;

	va_start(ap, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", seperator, va_arg(ap, int));
					break;
				case 'i':
					printf("%s%d", seperator, va_arg(ap, int));
					break;
				case 'f':
					printf("%s%f", seperator, va_arg(ap, double));
					break;
				case 's':
					str = va_arg(ap, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", seperator, str);
					break;
				default:
					i++;
					continue;
			}

			seperator = ", ";
			i++;
		}
	}

	printf("\n");
	va_end(ap);
}
