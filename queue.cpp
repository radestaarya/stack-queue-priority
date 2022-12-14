#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next, *prev;
}*front, *rear;

Node *createNode(int value){
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void enqueue(int value){
    Node *temp = createNode(value);

    if(!front){
        front = rear = temp;
    }
    else if(rear == front){
        rear -> prev = temp;
        temp -> next = rear;
        rear = temp;
    }
    else{
        rear -> prev = temp;
        temp -> next = rear;
        rear = temp;
    }
}

void dequeue(){
    if(!front){
        return;
    }
    else if(rear == front){
        free(rear);
        free(front);
        rear = front = NULL;
    }
    else{
        Node *temp = front -> prev;
        free(front);
        front = temp;
        front -> next = NULL;
    }
}

void readNode(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printNode(){
    for (Node *temp = rear; temp != NULL; temp = temp -> next){
        readNode(temp);
        puts("|");
        puts("V");
    }
}

int main(){
    enqueue(30);
    enqueue(20);
    enqueue(40);
    enqueue(10);

    dequeue();
    printNode();

    return 0;
}
