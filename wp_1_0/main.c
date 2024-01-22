#include <stdio.h>

int main(const int argc, const char **argv) {
    u_int32_t n = 0;
    char c = argv[1][0];
    int i = 0;

    printf("Number: %d\n", n);
    do {
        n *= 10;
        n += (c - '0');
        c = argv[1][++i];
    } while (c != '\0');

    const u_int32_t flipper = 0b10000000000000000000000000000000;
    printf("Binary: 0b");

    int zeros = 0;
    int ones = 0;

    const int s = sizeof(u_int32_t) * 8 + 1;
    for (int i2 = 0; i < s; i++) {
        const int bit = (n & flipper) != 0;

        if (bit)
            ones++;
        else if (ones > 0)
            zeros++;

        if (ones > 0)
            printf("%d", bit);
        n = n << 1;
    }

    printf("\nNumber of 0s: %d\nNumber of 1s: %d\n", zeros, ones);
}
