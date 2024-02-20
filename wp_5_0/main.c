#include <stdio.h>   // includes standard input/output library
#include <stdlib.h>   // includes standard library for strtol

unsigned char bits[5] = {1, 3, 2, 1, 1};   // defines amount of bits for each part
unsigned char maxes[5] = {1, 7, 1, 1, 1};   // defines maximum value for each part

// defines function which prints a hex number
char printHex(unsigned char number) {
    if (number > 9)   // if number should be represented by letter
        return number - 10 + 'A';   // calculate letter
    return number + '0';   // return number as char
}

// main function
int main(int argc, char **argv) {
    char *end;   // defines pointer to use with strtol
    unsigned char tmp, number = 0;   // defines temporary variable for parsing and output number

    if (argc != 6) {   // if there are not 5 arguments
        printf("Invalid input, five arguments expected\n");
        return 0;   // exit program
    }

    // for each argument
    for (unsigned char i = 1; i < argc; i++) {
        tmp = strtol(argv[i], &end, 10);   // parse argument as number

        // if parsing failed or number is out of range
        if (*end != '\0' || tmp < 0 || tmp > maxes[i - 1]) {
            printf("Invalid input");
            return 0;   // exit program
        }

        number |= tmp;   // add the parsed number to the output
        if (i != 5)   // if it's not the last number
            number <<= bits[i];   // shift the output to the left
    }

    printf("0x%c%c\n", printHex(number >> 4), printHex(number & 0b00001111));
}