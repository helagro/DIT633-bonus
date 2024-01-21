#include <stdio.h>

int main(int argc, char *argv[])
{
    int number = 34;
    int *numberPtr = &number;

    printf("number: %d\n", number);
    printf("&number: %d\n", &number);
    printf("numberPtr: %d\n", numberPtr);
    printf("*numberPtr: %d\n", *numberPtr);

    return 0;
}