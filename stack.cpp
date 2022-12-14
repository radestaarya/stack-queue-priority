#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    Node *next, *prev;
}*head, *tail;

Node *createNode(int value){
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void pushStack(int value)
{
    Node *temp = createNode(value);

    if(!head)
    {
        head = temp;
    }
    else
    {
        head -> next = temp;
        temp -> prev = head;
        head = temp;
    }
}

void pop()
{
    if(!head){
        return;
    }
    else if(!head -> prev){
        free(head);
        head = NULL;
    }
    else{
        Node *temp;
        temp = head -> prev;
        free(head);
        head = temp;
    }
}

void readNode(Node *currentNode)
{
    Node *nodePertama = currentNode;
    printf("Value: %d\n", nodePertama -> value);
    printf("Alamat node sekarang: %p\n", nodePertama);
    printf("Alamat node setelahnya: %p\n", nodePertama -> next);
}

void printNode()
{
    for(Node *temp = head; temp != NULL; temp = temp -> prev)
    {
        readNode(temp);
        puts("|");
        puts("V");
    }
    puts("NULL");
}

int main(){
    pushStack(20);
    pushStack(30);
    pushStack(15);
    pushStack(13);

    pop();
    printNode();
    

    return 0;
}
