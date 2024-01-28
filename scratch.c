#include <stdio.h>

int main(int argc, char *argv[]) {
    char dd[2][4] = {{'1', '2', '3', '\0'}, {'4', '5', '6', '\0'}};
    char *strArr = {"123", "123"};

    strArr[1] = "12";

    printf("%d\n", sizeof(dd) / sizeof(char));
    printf("%d\n", sizeof(strArr) / sizeof(char));

    return 0;
}