#include <stdio.h>
#include <stdlib.h>

unsigned char bits[5] = {1, 3, 2, 1, 1};
unsigned char maxes[5] = {1, 7, 1, 1, 1};

char printHex(unsigned char numbers) {
    const unsigned char number = numbers[0] * 8 + numbers[1] * 4 + numbers[2] * 2 + numbers[3];
    if (number > 9)
        return number - 9 + 'A';
    return number + '0';
}

int main(int argc, char **argv) {
    char *end;

    if (argc != 6) {
        printf("Invalid input, five arguments expected\n");
        return 0;
    }

    unsigned char number = 0, tmp = 0;

    for (unsigned char i = 1; i < argc; i++) {
        tmp = strtol(argv[i], &end, 10);
        if (*end != '\0' || tmp < 0 || tmp > maxes[i - 1]) {
            printf("Invalid input");
            return 0;
        }

        number |= tmp;
        if (i != 5)
            number <<= bits[i];
    }

    printf("%c%c\n", printHex(number >> 4), printHex(number & 0b00001111));
}