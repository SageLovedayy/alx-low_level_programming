#include "main.h"
#include <stdlib.h>

/**
 * is_space - checks if a character is a space, tab or newline
 * @c: character to check
 * Return: 1 if the character is space or tab or newline; 0 otherwise
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
* count_words - counts number of words in a string
* @str: input string
* Return: Number of words in the string
*/
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (is_space(*str))
		{
			in_word = 0;
		} else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}

	return (count);
}

/**
 * duplicate_word - Creates a duplicate copy of a word
 * @start: starting address of the word
 * @length: length of the word
 * Return: Pointer to the duplicated word; null for failed malloc
 */
char *duplicate_word(char *start, int length)
{
	int i;
	char *word = (char *)malloc((length + 1) * sizeof(char));

	if (word == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)
	{
		word[i] = start[i];
	}
	word[length] = '\0';

	return (word);
}

/**
* strtow - splits a string into words
* @str: Input string to be split
* Return: Pointer to an array of words. NULL on failure
*/
char **strtow(char *str)
{
	int word_count, in_word, word_index;
	char **words;
	char *word_start;

	word_count = count_words(str);
	in_word = word_index = 0;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}
	word_start = str;
	while (*str)
	{
		if (is_space(*str))
		{
			if (in_word)
			{
				words[word_index++] = duplicate_word(word_start, str - word_start);
				in_word = 0;
			}
		} else if (!in_word)
		{
			word_start = str;
			in_word = 1;
		}
		str++;
	}
	if (in_word)
	{
		words[word_index++] = duplicate_word(word_start, str - word_start);
	}
	words[word_index] = NULL;
	return (words);
}
