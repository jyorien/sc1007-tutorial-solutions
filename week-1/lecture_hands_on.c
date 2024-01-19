#include <stdlib.h>
#include <stdio.h>
struct mystruct {
    int number;
    struct mystruct *next_struct;
};

int main() {
    struct mystruct *ptr;
    ptr = malloc(sizeof(struct mystruct));
    ptr->number = 1;
    ptr->next_struct = malloc(struct mystruct);
    ptr->next_struct->number = 2;
    ptr->next_struct->next_struct = NULL;
}