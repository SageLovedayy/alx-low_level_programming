#include "lists.h"

void __attribute__((constructor)) hareTortoise(void);

/**
 * hareTortoise - Prints string before execution of main
 * function, using the  GCC-specific __attribute__((constructor))
 * feature.
 */
void hareTortoise(void)
{
printf("You're beat! and yet, you must allow,\n"
"I bore my house upon my back!\n");
}
