#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DEFAULT_PORTIONS 2.0
#define EPSILON 0.00001

int main(int argc, const char * * argv)
{
    double portions = (argc > 1) ? strtol(argv[1], NULL, 10) : DEFAULT_PORTIONS;

    char * line = NULL;
    size_t line_size = 0;
    int line_len;
    if ((line_len = getline(&line, &line_size, stdin)) == -1) {
        exit(EXIT_FAILURE);
    }
    line_len--; // NUL character

    double segment_len = line_len / portions;

    if ((segment_len - floor(segment_len)) > (EPSILON * segment_len)) {
        putchar(*line++);
        segment_len = floor(segment_len);
    }

    for (int i = 0; i < portions; i++) {
        for (int j = 0; j < segment_len; j++) {
            putchar(*line++);
        }
        putchar(' ');
    }

    putchar('\n');

    return 0;
}

