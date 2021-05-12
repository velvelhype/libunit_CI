#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char cat[] = "one";
    char *dog;
    dog = malloc(10);

    write(1, cat, 1);
    write(1, cat +111, 1);
    write(1, dog +111, 1);
}