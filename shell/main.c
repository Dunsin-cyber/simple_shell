#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "main.h"

/**
 * main - main Entry
 * Return: Integer
 */

int main(/* int argc, char argv */)
{
    size_t input_buf_size = 15;
    char *input_buf = NULL; /* we can calculate the size using malloc but getline function does the calculation for us under the hood */
    char *input_buf_cpy = NULL;
    int loop_determinant = 1;
    ssize_t getline_retrn;

    while (loop_determinant == 1)
    {
        /* start prompt that every user sees */
        printf("....$  ");

        /* get the input from the user */
        getline_retrn = getline(&input_buf, &input_buf_size, stdin);
        if (getline_retrn == -1)
        {
            printf("\nExiting ....$\n");
            return (-1);
        }

        /* print out what was inputed */
        printf("%s\n", input_buf);

        /* Duplicate string */
        input_buf_cpy = malloc(sizeof(char) * _strlen(input_buf));
        _strcpy(input_buf_cpy, input_buf);
    }
    free(input_buf);

    return (0);
}

/*  * @argc: length of argument vector
 * @argv: array of character pointers */