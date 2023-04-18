#include <main.h>

int main(int ac, char **argv)
{
	char *promp = "$ ";
	char *lineptr;
	size_t n = 0; 

	printf("%s", promp);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return 0;

}
