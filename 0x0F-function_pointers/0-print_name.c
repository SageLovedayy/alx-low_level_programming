#include "function_pointers.h"
#include "stdlib.h"
/**
 * print_name - prints name
 * @name: name to print
 * @f: pointer to function
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL) /*check for null pointers*/
		return;

	f(name); /*assignment to function is unneccessary*/
}
