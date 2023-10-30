#include "main.h"

/**
 * _strlen - calculates length of a string
 * @str: string
 * Return: length
 */
size_t _strlen(char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * append_text_to_file - appends text at end of a file
 * @filename: name of file
 * @text_content: null terminated string to add at end of file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1); /*Nothing to append, return 1 to indicate success*/

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	bytes_written = write(fd, text_content, _strlen(text_content));
	if (bytes_written == -1 || (size_t)bytes_written != _strlen(text_content))
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}

