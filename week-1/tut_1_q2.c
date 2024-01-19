#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int value;
    struct Node *nextNode;
};
typedef struct Node Node;

Node *createNode(int value)
{
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->nextNode = NULL;
    return new;
}

void insertNodeAtEnd(Node **head, Node *nodeToInsert)
{
    Node *temp = *head;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = nodeToInsert;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->nextNode;
    }
}

int main()
{
    Node *head = createNode(0);
    int res = -999;
    printf("Enter a list of numbers, terminated by the value -1:\n");
    while (1)
    {
        scanf("%d", &res);
        if (res == -1) break;
        Node *newNode = createNode(res);
        insertNodeAtEnd(&head, newNode);
    }

    printList(head->nextNode);
}
