#ifndef main_h
#define main_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <elf.h>

#define BUFFER_SIZE 1024

size_t _strlen(char *str);
int _putchar(char);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int copyFiles(const char *file_from, const char *file_to);
void handleError(int error_code, const char *file_name);
int main(int argc, char *argv[]);

#endif /*main.h*/
