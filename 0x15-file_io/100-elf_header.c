#include "main.h"

/**
* displayElfHeaderInfo - add descr
* @elfHeader: add descr
*/
void displayElfHeaderInfo(const Elf64_Ehdr *elfHeader)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
		printf("%02x ", elfHeader->e_ident[i]);

	printf("\n");

	printf("  Class:                             %s\n", elfHeader->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid");
	printf("  Data:                              %s\n", elfHeader->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Invalid");
	printf("  Version:                           %d (current)\n", elfHeader->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", elfHeader->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Invalid");
	printf("  ABI Version:                       %d\n", elfHeader->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", elfHeader->e_type == ET_EXEC ? "EXEC (Executable file)" : "Invalid");
	printf("  Entry point address:               %lx\n", (unsigned long)elfHeader->e_entry);
}

/**
* main - add descr
* @argc: add descr
* @argv: add descr
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	Elf64_Ehdr elfHeader;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Could not open file '%s'\n", argv[1]);
		exit(98);
	}


	if (read(fd, &elfHeader, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr) || elfHeader.e_ident[EI_MAG0] != ELFMAG0 ||
		elfHeader.e_ident[EI_MAG1] != ELFMAG1 || elfHeader.e_ident[EI_MAG2] != ELFMAG2 || elfHeader.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: '%s' is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	displayElfHeaderInfo(&elfHeader);

	close(fd);
	return (0);
}
