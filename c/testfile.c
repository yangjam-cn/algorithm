#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    int exit_status = EXIT_SUCCESS;
    while (*(++argv)  !=  NULL) {
        FILE *input = fopen(*argv, "r");
        if (input == NULL) {
            perror(*argv);
            exit_status = EXIT_FAILURE;
            continue;
        }
        printf("\n%s:\n", *argv);
        char ch;
        while ((ch = fgetc(input)) != EOF) {
            printf("%c", ch);
        }
        if (fclose(input) != 0) {
            perror(*argv);
            exit_status = EXIT_FAILURE;
        }
    }
    return exit_status;
}