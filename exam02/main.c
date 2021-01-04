#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int r;
    char *line;

    line = NULL;
    while ((r = get_next_line(&line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    line = NULL;
}