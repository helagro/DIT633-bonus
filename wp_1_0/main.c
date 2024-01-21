#include <stdio.h>

int main(const int argc, const char **argv) {
    int n = 0;
    char c = argv[1][0];
    int i = 0;

    printf("Number: %d\n", n);
    do {
        n *= 10;
        n += (c - '0');
        c = argv[1][++i];
    } while (c != '\0');

    printf("Binary: 0b%d", n << 1);

    printf("%d\n", n);
}
