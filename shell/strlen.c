#include <string.h>

/**
 * _strlen - Returns the length of a string
 * @s:character
 * Return: Integer
 */

int _strlen(char *s)
{
    int count = 0;

    while (*s != '\0')
    {
        count++;
        s++;
    }
    return (count);
}