#include "dog.h"
#include <stdlib.h>

/**
* mystrlen - calculates length of a string
* @str: string
* Return: length of string
*/
int mystrlen(char *str)
{
	int length;

	length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}

/**
* mystrcpy - copies a string to another
* @dest: destination string
* @src: source string
*/
void mystrcpy(char *dest, char *src)
{
	if (dest == NULL || src == NULL)
	{
		return;
	}

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
}

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age
 * @owner: owner
 * Return: new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	if (name == NULL || owner == NULL || age < 0)
	{
		return (NULL);
	}


	new_dog = malloc(sizeof(dog_t));

	if (new_dog == NULL)
	{
		return (NULL);
	}

	new_dog->name = malloc(mystrlen(name) + 1);
	new_dog->owner = malloc(mystrlen(owner) + 1);

	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		free(new_dog);
		free(new_dog->name);
		free(new_dog->owner);
		return (NULL);
	}

	mystrcpy(new_dog->name, name);
	mystrcpy(new_dog->owner, owner);

	new_dog->age = age;

	return (new_dog);
}
