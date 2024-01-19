#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void insertElement(char ele, char **str, int numOfChars);
void removeFirst(char **str);
int main() {
    int numOfChars;
    printf("How many characters do you want to input:");
    scanf("%d", &numOfChars);
    char *str = malloc(numOfChars+1);
    printf("Input the string: ");
    scanf("%s", str);
    char **strPtr = &str;
    int decision = -1;
    while (decision != 3) {
        printf("Do you want to 1-insert or 2-remove or 3-quit?: \n");
        scanf("%d", &decision);
        switch (decision) {
            case 1: {
                char c = 'a';
                printf("What is the character you want to insert: \n");
                scanf(" %c", &c);
              
                insertElement(c, strPtr, numOfChars);
                printf("%s\n", *strPtr);
                break;
            }
                
            case 2:
                removeFirst(strPtr);
                printf("%s\n", *strPtr);
            break;
            default:
            return 0;
            break;
        }

    }
}

// realloc to accommodate all chars
// void insertElement(char ele, char **str) {
//     int newSize = strlen(*str)+1;
//     *str = realloc(*str, newSize * sizeof(char));
//     for (int i = strlen(*str); i >= 0; i--) {
//         (*str)[i+1] = (*str)[i];
//     }
//     (*str)[0] = ele;

// }

// remove last ele when insert infront
void insertElement(char ele, char **str, int numOfChars) {
    for (int i = strlen(*str); i >= 0; i--) {
        (*str)[i+1] = (*str)[i];
    }
    (*str)[0] = ele;
    (*str)[numOfChars] = '\0';

}

void removeFirst(char **str) {
    printf("%lu\n", strlen(*str));
    for (int i =1; i < strlen(*str); i++) {
        (*str)[i-1] = (*str)[i];
    }
    (*str)[strlen(*str)-1] = '\0';
}
