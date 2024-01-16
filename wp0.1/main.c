// Includes the standard input/output library
#include <stdio.h>
#include <string.h>

#define MIN_NAME_LENGTH 3
#define MAX_NAME_LENGTH 50

// The entry point of the program
int main(const int argc, const char *argv[]){
    if(argc < 2){ // If there are no command line arguments
        printf("No command line argument provided, please provide a name.\n");
        return 1; // Returns 1 to indicate an error
    }

    // Gets the length of the first argument
    const int nameLength = strlen(argv[1]);

    // If the length of the first argument is shorter than the minimum allowed
    if(nameLength < MIN_NAME_LENGTH){
        printf("Name too short, min %d characters\n", MIN_NAME_LENGTH);
        return 1; // Returns 1 to indicate an error

    // If the length of the first argument is longer than the maximum allowed
    } else if (nameLength > MAX_NAME_LENGTH){
        printf("Name too long, max %d characters\n", MAX_NAME_LENGTH);
        return 1; // Returns 1 to indicate an error
    }
    
    // Prints "hello world" to the console
    printf("Hello %s, how is your day today?\n", argv[1]);
}