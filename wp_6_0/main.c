#include <stdio.h>   // includes standard input/output library
#include <stdlib.h>   // includes standard library for malloc
#include <string.h>   // includes string library for strlen

#define INPUT_AMT     5   // defines amount of strings to read
#define MAX_WORD_SIZE 211   // defines maximum size of a string

// defines function which returns array with shortest string removed and prints the removed string
char **popShortest(char input[INPUT_AMT][MAX_WORD_SIZE]) {
    // initializes pointer for shortest string, and array for the result
    char *shortest = NULL, **res = malloc((INPUT_AMT - 1) * sizeof(char *));
    // initializes counter for the result and the length of the shortest string
    unsigned char j = 0, shortestLen = MAX_WORD_SIZE + 1;

    // loops through strings
    for (unsigned char i = 0; i < INPUT_AMT; i++) {
        unsigned char len = strlen(input[i]);   // gets length of string
        if (len < shortestLen) {   // if string is shorter than the shortest
            if (shortest != NULL)   // if there is a previous shortest string
                res[j++] = shortest;   // stores it in the result
            shortest = input[i];   // remembers the new shortest string
            shortestLen = len;   // remembers the length of the new shortest string
        } else   // if string is not shorter than the shortest
            res[j++] = input[i];   // adds it to the result
    }

    printf("Shortest string removed: %s\n", shortest);

    return res;   // returns the result
}

// defines function which reads 2d char array from stdin
void readStr(char input[INPUT_AMT][MAX_WORD_SIZE]) {
    char c;   // defines temporary variable for reading characters

    // for each string
    for (unsigned char i = 0; i < INPUT_AMT; i++) {
        unsigned char j = 0;   // initializes counter for the string

        // while not at the end of the line
        while ((c = getchar()) != '\n' && c != EOF) {
            if (j == MAX_WORD_SIZE - 1)   // if string is too long
                input[i][j] = '\0';   // adds null terminator early
            else if (j < MAX_WORD_SIZE)   // if string is not too long
                input[i][j] = c;   // adds character to the string

            j++;   // increments word counter
        }

        if (j < MAX_WORD_SIZE)   // if string is not too long
            input[i][j] = '\0';   // adds null terminator
    }
}

// defines main function
int main() {
    char input[INPUT_AMT][MAX_WORD_SIZE];   // defines array for input strings
    readStr(input);   // reads input strings from stdin
    printf("Array before removal:\n");
    for (unsigned char i = 0; i < INPUT_AMT; i++)   // loops through input
        printf("%s\n", input[i]);

    char **res = popShortest(input);   // returns array with shortest string removed

    printf("Array after removal:\n");
    for (unsigned char i = 0; i < INPUT_AMT - 1; i++)   // loops through result
        printf("%s\n", res[i]);

    free(res);   // frees memory used by result
}