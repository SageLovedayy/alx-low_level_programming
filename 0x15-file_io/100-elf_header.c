#include "main.h"

int main(int argc, char *argv[])
{
	int fileDescriptor, bytesRead, i;
	Elf64_Ehdr elfHeader;
	ElfMagicNumber magic;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	bytesRead = read(fileDescriptor, &elfHeader, sizeof(Elf64_Ehdr));
	if (bytesRead == -1)
	{
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	for (i = 0; i < EI_NIDENT; i++)
		magic[i] = elfHeader.e_ident[i];

	validateElfFile(magic);

	printf("ELF Header:\n");
	printElfMagicNumber(magic);
	printElfClass(magic[EI_CLASS]);
	printElfData(magic[EI_DATA]);
	printElfVersion(magic[EI_VERSION]);
	printOsAbi(magic[EI_OSABI]);
	printAbiVersion(magic[EI_ABIVERSION]);
	printElfType(elfHeader.e_type);
	printEntryPoint(elfHeader.e_entry, magic[EI_CLASS], magic[EI_DATA]);

	closeFile(fileDescriptor);
	return (0);
}

void validateElfFile(const ElfMagicNumber magic)
{
	if (magic[EI_MAG0] != ELFMAG0 || magic[EI_MAG1] != ELFMAG1 ||
		magic[EI_MAG2] != ELFMAG2 || magic[EI_MAG3] != ELFMAG3) {
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

void printElfMagicNumber(const ElfMagicNumber magic)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", magic[i], (i == EI_NIDENT - 1) ? "\n" : " ");
}

void printElfClass(unsigned char elfClass)
{
	printf("  Class:                             ");
	switch (elfClass)
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", elfClass);
			break;
	}
}

void printElfData(unsigned char elfData)
{
	printf("  Data:                              ");
	switch (elfData)
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", elfData);
			break;
	}
}

void printElfVersion(unsigned char elfVersion)
{
	printf("  Version:                           %d", elfVersion);
	if (elfVersion == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

void printOsAbi(unsigned char osAbi)
{
	printf("  OS/ABI:                            ");
	switch (osAbi)
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;

		default:
			printf("<unknown: %x>\n", osAbi);
			break;
	}
}

void printAbiVersion(unsigned char abiVersion)
{
	printf("  ABI Version:                       %d\n", abiVersion);
}

void printElfType(unsigned int elfType)
{
	printf("  Type:                              ");

	switch (elfType)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", elfType);
			break;
	}
}

void printEntryPoint(unsigned long int entryPoint, unsigned char elfClass
, unsigned char elfData)
{
	printf("  Entry point address:               ");
	if (elfClass == ELFCLASS32)
		printf("%#x\n", (unsigned int)entryPoint);
	else if (elfClass == ELFCLASS64)
		printf("%#lx\n", entryPoint);
	else
		printf("Unknown ELF class\n");
}

void closeFile(int fileDescriptor)
{
	if (close(fileDescriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(98);
	}
}
