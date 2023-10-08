#include "shell.h"

/**
 * check_interactive - checks if shell is in interactive mode
 * @info: pointer to the info_t struct
 * Return: 1 if interactive mode, 0 otherwise
 */
int check_interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 * Return: 1 if it's a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delim)
{
while (*delim)
{
if (*delim == c)
return (1);
delim++;
}
return (0);
}

/**
 * is_alpha - checks if a character is alphabetic
 * @c: the character to check
 * Return: 1 if it's alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 * Return: the converted integer or 0 if no numbers in string
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result = result * 10 + (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
return (-result);
return (result);
}