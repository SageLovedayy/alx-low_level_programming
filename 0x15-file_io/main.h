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
void error_file(int file_from, int file_to, char *argv[]);
int main(int argc, char *argv[]);
void displayElfHeaderInfo(const Elf64_Ehdr *elfHeader);

typedef unsigned char ElfMagicNumber[EI_NIDENT];
void validateElfFile(const ElfMagicNumber magic);
void printElfMagicNumber(const ElfMagicNumber magic);
void printElfClass(unsigned char elfClass);
void printElfData(unsigned char elfData);
void printElfVersion(unsigned char elfVersion);
void printOsAbi(unsigned char osAbi);
void printAbiVersion(unsigned char abiVersion);
void printElfType(unsigned int elfType);
void printEntryPoint(unsigned long int entryPoint, unsigned char elfClass
, unsigned char elfData);
void closeFile(int fileDescriptor);

void print_elf_header_info(Elf64_Ehdr *elf_header);

#endif /*main.h*/
