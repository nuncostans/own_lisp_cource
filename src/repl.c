#include <stdio.h>
#include <stdlib.h>
// if win
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// fake readline
char* readline(char* prompt)
{
        fputs(prompt, stdout);
        fgets(buffer, 2048, stdin);
        char* cpy = malloc(strlen(buffer)+1);
        strcpy(cpy, buffer);
        cpy[strlen(cpy)-1] = '\0';
        return cpy;
}
// fake add_history function
void add_history(char* unused){}

//otherwise include the editline headers
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

static char input[2048];

int main(int argc, char** argv)
{
        puts("Lispy version 0.0.0.0.1");
        puts("Press Ctrl+C to exit\n");

        while(1)
        {
                char* input  = readline("lispy> ");
                add_history(input);
                printf("No you are a %s\n", input);
                free(input);
        }
        return 0;
}
