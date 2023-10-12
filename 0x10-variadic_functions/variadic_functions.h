#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);

void print_char(char value, const char *seperator);
void print_integer(int value, const char *seperator);
void print_float(float value, const char *seperator);
void print_string(char *value, const char *seperator);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
