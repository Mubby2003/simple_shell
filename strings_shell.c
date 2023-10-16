#include "shell.h"

/**
 * _strlen - A function that returns the length of a string.
 * @s: character string.
 * *
 * Return: length of the string.
 */
int _strlen(char *s)
{
	char *ptr = s;

	while (*ptr != '\0')
	{
		ptr++;
	}

	return (ptr - s);
}

/**
 * _strcmp - A function that compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: (0) when they are the same, positive if s1 > s2, negative if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * *
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
	{
		/* Handles NULL pointers */
		return (NULL);
	}

	char *original_Dest = dest;/* Stores the original destination pointer*/

	while ((*dest++ = *src++))
	{
		/* Copies the characters from source to destination */
	}

	return (original_Dest); /* Returns the original destination pointer */
}

/**
 * _strdup - A function that copies a string.
 * @str: String to be copied.
 * *
 * Return: A character pointer to the newly allocated string in memory.
 */
char *_strdup(char *str)
{
	char *dest;
	int str_size, k;

	if (str == NULL)
	{
		return (NULL);
	}

	str_size = _strlen(str) + 1;
	dest = malloc(str_size * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}

	for (k = 0; k < str_size - 1; k++)
	{
		dest[k] = str[k];
	}
	dest[k] = '\0';
/*Null terminator added to the end of the destination string*/

	return (dest);
}
