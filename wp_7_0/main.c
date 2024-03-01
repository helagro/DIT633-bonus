#include <stdio.h>   // include standard input/output library
#include <stdlib.h>   // include standard library for malloc and free

// defines list item struct
struct Elem {
    unsigned long long value;   // value of item
    struct Elem *prev;   // pointer to previous item in list
};

// defines function that appends new item to list
struct Elem *append(struct Elem *head, unsigned long long value) {
    struct Elem *new = malloc(sizeof(struct Elem));   // allocate memory for new item
    new->value = value;   // set value of new item
    new->prev = head;   // set previous item of new item to head
    return new;   // return pointer to new item
}

// defines main function
int main(int argc, char **argv) {
    if (argc != 2) {   // if wrong amount of arguments
        printf("Invalid input, one argument expected\n");
        return 0;   // exit program
    }

    char *end;   // define pointer used for strtol
    long input = strtol(argv[1], &end, 10);   // convert argument to long
    if (*end != '\0') {   // if not valid number
        printf("Invalid input\n");
        return 0;   // exit program
    }

    if (input < 0) {   // if negative number
        printf("0");
        return 0;   // exit program
    }

    struct Elem *head = malloc(sizeof(struct Elem));   // allocate memory for head of list
    head->value = 0;   // set value of first item to 0
    head->prev = NULL;   // set previous item of first item to NULL
    head = append(head, 1);   // append new item with value 1 to list

    for (long i = 1; i < input; i++)   // iterate from 1 to input
        head = append(head, head->value + head->prev->value);   // add next item

    while (head != NULL) {   // iterate through list
        printf("%llu\n", head->value);

        struct Elem *tmp = head;   // set temporary pointer to head
        head = head->prev;   // set head to previous item

        free(tmp);   // free memory of temporary pointer
    }
}