#include <stdio.h>
#include <unistd.h>

#define BAD_NUM_INPUT -1

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN, INVALID_DAY };
enum Week { WEEK_1, WEEK_2, WEEK_3, WEEK_4, WEEK_5, INVALID_WEEK };

enum Week readWeek();
enum Day readDay();
char readOneBasedIndex(char min, char max);
void printDays(const enum Week week, enum Day day);
void printDay(enum Day day);

int main() {
    enum Week week = readWeek();
    if (week == INVALID_WEEK)
        return 0;

    enum Day day = readDay();
    if (day == INVALID_DAY)
        return 0;

    printDays(week, day);

    return 0;
}

enum Week readWeek() {
    char c = readOneBasedIndex(WEEK_1, WEEK_5);

    if (c == BAD_NUM_INPUT) {
        printf("invalid week\n");
        return INVALID_WEEK;
    } else {
        return c;
    }
}

enum Day readDay() {
    char c = readOneBasedIndex(MON, SUN);

    if (c == BAD_NUM_INPUT) {
        printf("invalid day\n");
        return INVALID_DAY;
    } else {
        return c;
    }
}

char readOneBasedIndex(char min, char max) {
    char c = getchar() - '1';

    char trash;
    while ((trash = getchar()) != EOF && trash != '\n')
        ;

    if (c < min || c > max) {
        return BAD_NUM_INPUT;
    } else {
        return c;
    }
}

void printDays(const enum Week week, enum Day day) {
    for (char w = week; w <= WEEK_5; w++) {
        for (char d = day; d <= SUN; d++) {
            printf("Week %d, ", w + 1);
            printDay(d);
            sleep(1);
        }

        day = MON;
    }
}

void printDay(enum Day day) {
    switch (day) {
        case MON:
            printf("Monday\n");
            break;
        case TUE:
            printf("Tuesday\n");
            break;
        case WED:
            printf("Wednesday\n");
            break;
        case THU:
            printf("Thursday\n");
            break;
        case FRI:
            printf("Friday\n");
            break;
        case SAT:
            printf("Saturday\n");
            break;
        case SUN:
            printf("Sunday\n");
            break;
        default:
            fprintf(stderr, "Error: Invalid day\n");
            break;
    }
}