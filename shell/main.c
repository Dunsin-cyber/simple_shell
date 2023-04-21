#include "main.h"

/**
 * main - main Entry
 * Return: Integer
 */

int main()
{
    size_t input_buf_size = 15;
    char *input_buf = NULL; /* we can calculate the size using malloc but getline function does the calculation for us under the hood */
    char *input_buf_cpy = NULL;
    int loop_determinant = 1;
    ssize_t getline_retrn;
    char *strtok_rtrn;
    int strtok_rtrn_num;
    char **arg;
    int i;
    char *command = NULL;
    /* char *splitted_strng = Null; */

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

        /* split the input command into stings */
        strtok_rtrn = strtok(input_buf, " ");
        while (strtok_rtrn != NULL)
        {
            strtok_rtrn = strtok(NULL, " ");
            strtok_rtrn_num++;
        }
        strtok_rtrn_num++;

        /* we need to allocate size to arg which will hold the array of strings*/
        arg = malloc(sizeof(char) * strtok_rtrn_num);

        strtok_rtrn = strtok(input_buf_cpy, " ");

        /* push in each string into arg */
        for (i = 0; strtok_rtrn != NULL; i++)
        {
            /* allocate space fro each character also */
            arg[i] = malloc(sizeof(char) * _strlen(strtok_rtrn));

            /*  copy each string into arg[i]*/
            _strcpy(arg[i], strtok_rtrn);

            strtok_rtrn = strtok(NULL, " ");
        }
        arg[i] = NULL;

        /* EXECUTE COMMAND */
        if (arg)
        {
            command = arg[0];
            if (execve(command, arg, NULL) == -1)
            {
                perror("Error");
            }
        }
    }

    free(arg), free(input_buf), free(input_buf_cpy);

    return (0);
}