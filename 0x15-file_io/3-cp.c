#include "main.h"

/**
* copyFiles - add descr
* @file_from: add descr
* @file_to: add descr
* Return: 1 on success, -1 on failure
*/
int copyFiles(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		return (-1);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
	S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		close(fd_from);
		return (-1);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			return (-1);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		return (-1);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		return (-1);
	}

	return (1);
}

/**
* handleError - add descr
* @error_code: add descr
* @file_name: add descr
*/
void handleError(int error_code, const char *file_name)
{
	switch (error_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", file_name);
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_name);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
			break;
	}
	exit(error_code);
}

/**
* main - add descr
* @argc: add descr
* @argv: add descr
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	int result;

	if (argc != 3)
		handleError(97, argv[0]);

	result = copyFiles(file_from, file_to);

	if (result == -1)
		handleError(errno == EACCES ? 98 : 99, file_from);

	return (0);
}
