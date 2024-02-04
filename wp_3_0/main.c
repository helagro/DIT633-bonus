#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int w;
    int h;
} SIZE;

/* ----------------------- COMPARATORS ---------------------- */

_Bool isSpace(char c) {
    return c == ' ';
}

_Bool isNlOrEof(char c) {
    return c == '\n' || c == EOF;
}

/* ------------------------ OTHER FUNCTIONS ----------------------- */

void printSum(int *matrix1, int *matrix2, SIZE *s) {
    for (int y = 0; y < s->h; y++) {
        for (int x = 0; x < s->w; x++) {
            printf("%d ", *matrix1 + *matrix2);
            matrix1++;
            matrix2++;
        }
        putchar('\n');
    }
}

_Bool readNum(int *output, _Bool (*fun)(char)) {
    *output = 0;
    char c = getchar();

    _Bool negate = c == '-';
    if (negate)
        c = getchar();

    while (!fun(c)) {
        if (c > '9' || c < '0')
            return 0;

        *output *= 10;
        *output += c - '0';

        c = getchar();
    }

    if (negate)
        *output *= -1;
    return c;
}

int *getMatrix(SIZE *s) {
    int n, elemCnt = s->w * s->h;
    int *matrix = malloc(sizeof(int) * elemCnt);
    if (matrix == NULL)
        return NULL;

    for (int i = 0; i < elemCnt; i++) {
        if (!readNum(&n, (i == elemCnt - 1) ? isNlOrEof : isSpace))
            return NULL;

        matrix[i] = n;
    }

    return matrix;
}

_Bool getSize(SIZE *output) {
    if (readNum(&output->w, isSpace) && readNum(&output->h, isNlOrEof) && output->w > 1 &&
        output->h > 1)
        return 1;
    else {
        printf("invalid input\n");
        return 0;
    }
}

int main() {
    printf("Input the size: ");
    SIZE s;
    if (!getSize(&s))
        return 0;

    printf("Input the matrix1: ");
    int *matrix1 = getMatrix(&s);

    printf("Input the matrix2: ");
    int *matrix2 = getMatrix(&s);

    if (matrix1 == NULL || matrix2 == NULL) {
        printf("Invalid input or failed to generate matrix\n");
        return 0;
    }

    printf("The sum is:\n");
    printSum(matrix1, matrix2, &s);

    free(matrix1);
    free(matrix2);
}