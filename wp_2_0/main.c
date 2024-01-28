#include <stdio.h>   // includes standard input / output library
#include <unistd.h>   // includes library for the sleep function

#define BAD_NUM_INPUT -1   // defines macro for bad number input

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN, INVALID_DAY };   // defines enum with days
enum Week { WEEK_1, WEEK_2, WEEK_3, WEEK_4, WEEK_5, INVALID_WEEK };   // defines enum with weeks

/* ------------------ FUNCTION DECLARATIONS ----------------- */

enum Week readWeek();   // declares function to read a week from stin
enum Day readDay();   // declares function to read a day from stdin

// declares function reading 1-based index from stdin, with min and max specified with 0-based index
char readOneBasedIndex(char min, char max);

// declares function to print days from specified day to sunday week 5
void printDays(const enum Week week, enum Day day);
void printDay(enum Day day);   // declares function to print name of specified day

/* ------------------ FUNCTION DEFINITIONS ------------------ */

// main function of the program
int main() {
    enum Week week = readWeek();   // reads week from stdin
    if (week == INVALID_WEEK)   // if week is invalid
        return 0;   // exits program

    enum Day day = readDay();   // reads day from stdin
    if (day == INVALID_DAY)   // if day is invalid
        return 0;   // exits program

    printDays(week, day);   // prints days from specified day to sunday week 5

    return 0;   // exits program
}

// defines function to read a week from stdin
enum Week readWeek() {
    // reads a week index from stdin
    char c = readOneBasedIndex(WEEK_1, WEEK_5);

    if (c == BAD_NUM_INPUT) {   // if week index is invalid
        printf("invalid week\n");
        return INVALID_WEEK;   // returns flag for invalid week
    } else {   // if week index is valid
        return c;   // returns week
    }
}

// defines function to read a day from stdin
enum Day readDay() {
    // reads a day index from stdin
    char c = readOneBasedIndex(MON, SUN);

    if (c == BAD_NUM_INPUT) {   // if day index is invalid
        printf("invalid day\n");
        return INVALID_DAY;   // returns flag for invalid day
    } else {   // if day index is valid
        return c;   // returns day
    }
}

// defines function reading 1-based index from stdin, with min and max specified with 0-based index
char readOneBasedIndex(char min, char max) {
    char c = getchar() - '1';   // reads a character from stdin and converts it to a 0-based index

    char trash;   // defines temporary variables used to clear stdin
    while ((trash = getchar()) != EOF && trash != '\n')   // clears stdin
        ;

    if (c < min || c > max) {   // if index is invalid
        return BAD_NUM_INPUT;   // returns flag for invalid index
    } else {   // if index is valid
        return c;   // returns index
    }
}

// defines function to print days from specified day to sunday week 5
void printDays(const enum Week week, enum Day day) {
    for (char w = week; w <= WEEK_5; w++) {   // loops through weeks
        for (char d = day; d <= SUN; d++) {   // loops through days
            printf("Week %d, ", w + 1);
            printDay(d);   // prints name of day
            sleep(1);   // delays program for 1 second
        }

        day = MON;   // sets day to monday to start the rest of weeks from monday
    }
}

// defines function to print name of specified day
void printDay(enum Day day) {
    switch (day) {   // switches on day
        case MON:   // if day is monday
            printf("Monday\n");
            break;   // breaks out of switch
        case TUE:   // if day is tuesday
            printf("Tuesday\n");
            break;   // breaks out of switch
        case WED:   // if day is wednesday
            printf("Wednesday\n");
            break;   // breaks out of switch
        case THU:   // if day is thursday
            printf("Thursday\n");
            break;   // breaks out of switch
        case FRI:   // if day is friday
            printf("Friday\n");
            break;   // breaks out of switch
        case SAT:   // if day is saturday
            printf("Saturday\n");
            break;   // breaks out of switch
        case SUN:   // if day is sunday
            printf("Sunday\n");
            break;   // breaks out of switch
        default:   // if day is invalid
            fprintf(stderr, "Error: Invalid day\n");
            break;   // breaks out of switch
    }
}