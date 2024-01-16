#include <stdio.h>

int main(int argc, char *argv[]) {
    const int intArray[] = {1, 2, 3, 4, 5};
    const char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    const size_t sizeOfCharArray = sizeof(charArray) / sizeof(char);

    const size_t sizeOfIntArray = sizeof(intArray) / sizeof(int);
    const size_t sizeOfInput = sizeof(&argv[1]) / sizeof(char);

    printf("Size of intArray: %zu\n", sizeOfIntArray);
    printf("Size of charArray: %zu\n", sizeOfCharArray);
    printf("Size of input: %zu\n", sizeOfInput);

    printf("chars %s!\n", charArray);

    return 0;
}