#include "main.h"

/**
 * *_strcpy - copy string pointed from an addrss to another
 * @dest: address
 * @src:address
 * Return: character
 */

char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; i <= _strlen(src); i++)
    {
        dest[i] = src[i];
    }
    return (dest);
}