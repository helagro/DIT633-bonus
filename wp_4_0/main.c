#include <stdio.h>   // includes standard input/output library
#include <stdlib.h>   // includes standard library which contains malloc and free

#define MAX_INPUT 11   // defines max size of input array

// initialises variables for number of permutations and letters
unsigned int permsN = 1, letters = 0;
// declares pointers for permutations array and for iterating through it
char **perms, **permsPtr;

// defines a function to swap two characters
void swap(char *c1, char *c2) {
    char tmp = *c2;   // initialises a temporary variable to store the value of c2
    *c2 = *c1;   // copies value of c1 to c2
    *c1 = tmp;   // copies value of tmp to c1
}

// defines a function to duplicate a string
char *dupStr(char *src) {
    // allocates memory for a new string and initalises pointer for iterating through it
    char *p = malloc(sizeof(char) * (letters + 1)), *q = p;

    do {   // loops through the source string
        *(q++) = *(src++);   // copies the value of the source string to the new string
    } while (*src != '\0');   // until the end of the source string is reached

    *q = '\0';   // adds a null terminator to the end of the new string
    return p;   // returns the new string
}

// defines a function to fill the permutations array
void fillPermutations(unsigned int i) {
    if (i == letters - 1)   // if the current index is the last letter
        return;   // exit the recursion

    unsigned int j = i + 1;   // initialises a variable for incremnenting through words
    char *refWord = *permsPtr;   // initialises a pointer to the current word

    do {   // loops through the word
        // creates permutations of word with all combinations of the words after index i
        fillPermutations(i + 1);
        *(++permsPtr) = dupStr(refWord);   // duplicates the word to the next index of array
        // swaps the first character of "visible word" with the jth character
        swap(&((*permsPtr)[i]), &((*permsPtr)[j++]));
    } while (j < letters);   // until the end of the word is reached

    // creates permutations of word with all combinations of the words after index i
    fillPermutations(i + 1);
}

// defines the main function
int main(int argv, char **argc) {
    // initialises a variable for incrementing through the first argument
    unsigned int firstArgI = 0;

    if (argv != 2) {   // if the number of arguments is not 1
        printf("Invalid input, one argument expected\n");
        return 0;   // exit the program
    }

    do {   // loops through the first argument
        permsN *= ++letters;   // calculates the number of permutations

        if (++firstArgI == MAX_INPUT) {   // if the first argument is too long
            printf("Invalid input, 1st argument is too long\n");
            return 0;   // exit the program
        }
    } while (argc[1][firstArgI] != '\0');   // until the end of the first argument is reached

    // allocates memory for the permutations array
    perms = permsPtr = malloc(permsN * sizeof(char *));
    *permsPtr = dupStr(argc[1]);   // duplicates the first argument to the first index of the array

    fillPermutations(0);   // fills the permutations array

    for (int i = 0; i < permsN; i++) {   // loops through the permutations array
        printf("%d: %s\n", i, perms[i]);   // prints permutations
        free(perms[i]);   // frees memory for the current permutation
    }

    free(perms);   // frees memory for the permutations array
}