#include <stdio.h>
#include <stdlib.h>

struct Elem {
    unsigned long long value;
    struct Elem *prev;
};

int main(int argc, char **argv) {
    unsigned long long value = 1;
    struct Elem head;
    head.value = 0;

    if (argc != 2) {
        printf("Invalid input, one argument expected\n");
        return 0;
    }

    char *end;
    long input = strtol(argv[1], &end, 10);
    if (*end != '\0') {
        printf("Invalid input\n");
        return 0;
    }

    for (unsigned int i = 1; i <= value; i++) {
    }
    printf("%ld\n", input);
}