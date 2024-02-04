#include <stdio.h>   // includes standard I/O library for getchar, printf, putchar
#include <stdlib.h>   // includes standard library for malloc, free

/* ----------------------- STRUCTS ---------------------- */

typedef struct {   // defines a struct for the size of the matrix
    int w;   // width
    int h;   // height
} SIZE;   // names the struct "SIZE"

/* ----------------------- COMPARATORS ---------------------- */

// defines a function that returns true if the provided character is a space
_Bool isSpace(char c) {
    return c == ' ';   // returns true if the provided character is a space
}

// defines a function that returns true if the provided character is a newline or EOF
_Bool isNlOrEof(char c) {
    return c == '\n' || c == EOF;   // returns true if the provided character is a newline or EOF
}

/* ------------------------ OTHER FUNCTIONS ----------------------- */

// defines a function that prints the sum of two matrices
void printSum(int *matrix1, int *matrix2, SIZE *s) {
    for (int y = 0; y < s->h; y++) {   // iterates through the rows of the matrix
        for (int x = 0; x < s->w; x++) {   // iterates through the columns of the matrix
            printf("%d ", *matrix1 + *matrix2);   // prints the sum of the cells of the two matrices
            matrix1++;   // increments the pointer to the first matrix
            matrix2++;   // increments the pointer to the second matrix
        }
        putchar('\n');   // prints a newline character
    }
}

// defines a function that reads a number from the standard input
_Bool readNum(int *output, _Bool (*fun)(char)) {
    *output = 0;   // sets the output to 0
    char c = getchar();   // initializes c with next character from stdin
    _Bool read = 0;   // initializes read to false

    _Bool negate = c == '-';   // sets negate to true if input starts with '-'
    if (negate)   // if input starts with '-'
        c = getchar();   // read the next character again

    while (!fun(c)) {   // while the provided function returns false for the read character
        if ((c > '9' || c < '0') && c != ' ')   // if the character is not a digit or a space
            return 0;   // return false

        if (c != ' ') {   // if the character is not a space
            read = 1;   // set read to true
            *output *= 10;   // multiply the output by 10
            *output += c - '0';   // add the numeric value of the character to the output
        }

        c = getchar();   // reads the next character from stdin
    }

    if (negate)   // if the input started with '-'
        *output *= -1;   // make the number negative
    return read;   // returns true if read a valid character
}

// defines a function which reads a matrix from the standard input
int *getMatrix(SIZE *s) {
    // initialises n which will store the read number and elemCnt to store the number of elements in
    // the matrix
    int n, elemCnt = s->w * s->h;

    int *matrix = malloc(sizeof(int) * elemCnt);   // allocates memory for the matrix
    if (matrix == NULL)   // if allocation failed
        return NULL;   // return NULL

    for (int i = 0; i < elemCnt; i++) {   // iterates through the elements of the matrix
        // reads number from stdin, stopping at newline or EOF if it's the last element, or at space
        // if it isn't. If it fails, returns NULL
        if (!readNum(&n, (i == elemCnt - 1) ? isNlOrEof : isSpace))
            return NULL;   // return NULL

        matrix[i] = n;   // sets the i-th element of the matrix to the read number
    }

    return matrix;   // returns the matrix
}

// defines a function that reads the size of the matrices
_Bool getSize(SIZE *output) {
    // if the numbers where read successfully and they are greater than 1
    if (readNum(&output->w, isSpace) && readNum(&output->h, isNlOrEof) && output->w > 1 &&
        output->h > 1)
        return 1;   // return true
    else {   // if the numbers where not read successfully or they are not greater than 1
        printf("invalid input\n");
        return 0;   // return false
    }
}

// defines the main function
int main() {
    printf("Input the size: ");
    SIZE s;   // declares a variable of type SIZE
    if (!getSize(&s))   // if the size was not read successfully
        return 0;   // quit the program

    printf("Input the matrix1: ");
    int *matrix1 = getMatrix(&s);   // reads the first matrix from the standard input

    printf("Input the matrix2: ");
    int *matrix2 = getMatrix(&s);   // reads the second matrix from the standard input

    if (matrix1 == NULL || matrix2 == NULL) {   // if the matrices were not read successfully
        printf("Invalid input or failed to generate matrix\n");
        return 0;   // quit the program
    }

    printf("The sum is:\n");
    printSum(matrix1, matrix2, &s);   // prints the sum of the two matrices

    free(matrix1);   // frees the memory allocated for the first matrix
    free(matrix2);   // frees the memory allocated for the second matrix
}