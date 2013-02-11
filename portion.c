#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DEFAULT_PORTIONS 2

int main(int argc, const char * * argv)
{
    long portions = (argc > 1) ? strtol(argv[1], NULL, 10) : DEFAULT_PORTIONS;

    char * line = NULL;
    size_t line_size = 0;
    int line_len;
    if ((line_len = getline(&line, &line_size, stdin)) == -1) {
        exit(EXIT_FAILURE);
    }
    line_len--; // NUL character

    int portion_len = line_len / portions;

    for (int i = 0; i < portions; i++) {
        if (i < line_len % portions) {
            putchar(*line++);
        }
        for (int j = 0; j < portion_len; j++) {
            putchar(*line++);
        }
        putchar(' ');
    }

    putchar('\n');

    return 0;
}

