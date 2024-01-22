// Include standard input output library for printing
#include <stdio.h>

/*
    Main function of the program. The program takes a number and returns information about the
   binary representation. It will return the wrong results if the number is larger than the integer
   of the system
*/
int main(const int argc, const char **argv) {

    // defines s as the amount of bits in an int
    const int s = sizeof(int) * 8;

    if (argc == 1) {   // if no argument provided
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        return 0;   // quits the progam
    }

    int n = 0, i = 0;      // initialises the result variable n and counter variable i
    char c = argv[1][0];   // initialises the char c as the first character of the first argument

    do {
        if (c < '0' || c > '9') {   // if the character is a number
            printf("Error: Invalid number.\n");
            return 0;   // quits the program
        }

        n *= 10;          // times itself by ten
        n += (c - '0');   // adds the inputed number to the result

        // changes c to the next char in the first argument, while incrementing i
        c = argv[1][++i];
    } while (c != '\0');   // while the string has characters

    printf("Number: %d\n", n);

    // initialises variable with the MSB as 1, all other bits 0 (regardless of size of int)
    const int filter = (1 << (s - 1));
    printf("Binary: 0b");

    // initalises the result variables for the amount the zeros and ones
    int zeros = 0, ones = 0;

    // loops through the bits of the result number
    for (int i2 = 0; i2 < s; i2++) {
        // essentially gets the currently most significant bit of n
        const int bit = (n & filter) != 0;

        if (bit)             // if MSB is 1
            ones++;          // increment one count
        else if (ones > 0)   // if MSB is 0 and we have "found" atleast one *one*
            zeros++;         // increment zero count

        if (ones > 0)   // if we have "found" atleast one *one*
            printf("%d", bit);
        n = n << 1;   // shift n one step to the right
    }

    printf("\nNumber of 0s: %d\nNumber of 1s: %d\n", zeros, ones);
}
