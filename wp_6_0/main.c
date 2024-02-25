#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_AMT     5
#define MAX_WORD_SIZE 211

char **popShortest(char input[INPUT_AMT][MAX_WORD_SIZE]) {
    char *shortest = NULL, **res = malloc((INPUT_AMT - 1) * sizeof(char *));
    unsigned char j = 0, shortestLen = MAX_WORD_SIZE + 1;

    for (unsigned char i = 0; i < INPUT_AMT; i++) {
        unsigned char len = strlen(input[i]);
        if (len < shortestLen) {
            if (shortest != NULL)
                res[j++] = shortest;
            shortest = input[i];
            shortestLen = len;
        } else
            res[j++] = input[i];
    }

    printf("Shortest string removed: %s\n", shortest);

    return res;
}

void readStr(char input[INPUT_AMT][MAX_WORD_SIZE]) {
    char c;

    for (unsigned char i = 0; i < INPUT_AMT; i++) {
        unsigned char j = 0;

        while ((c = getchar()) != '\n' && c != EOF) {
            if (j == MAX_WORD_SIZE - 1)
                input[i][j] = '\0';
            else if (j < MAX_WORD_SIZE)
                input[i][j] = c;

            j++;
        }

        if (j < MAX_WORD_SIZE)
            input[i][j] = '\0';
    }
}

int main() {
    char input[INPUT_AMT][MAX_WORD_SIZE];
    readStr(input);
    char **res = popShortest(input);

    printf("Array after removal:\n");
    for (unsigned char i = 0; i < INPUT_AMT - 1; i++)
        printf("%s\n", res[i]);
}