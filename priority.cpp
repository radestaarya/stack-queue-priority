#include <stdio.h>
#include <stdlib.h>

struct Node {
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

void pushPriority(int value){
    Node *temp = createNode(value);

    if(!front){ // No LL
        front = temp;
        rear = temp;
    }
    else if(value > front -> value){	// Value 
        front -> prev = temp;
        temp -> next = front;
        front = temp;
    }
    else if(value < rear -> value){		//  NULLL - front - 10 - 30 - 2 - rear - NULLQ
      	temp -> prev = rear;
      	rear -> next = temp;
      	rear = temp;
      	rear -> next = NULL;
    }
    else{
        Node* curr = rear;

        while(curr -> value > value){
            curr = curr -> prev;
        }
        temp -> prev = curr;
        curr -> next = temp;
    }

}

void readNode(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
}

void printNode(){
  for (Node *temp = front ; temp != NULL; temp = temp->next)
  {
    readNode(temp);
    puts("|");
    puts("v");
  }
  puts("NULL");
}

int main(){
    pushPriority(10);
    pushPriority(30);
    pushPriority(20);
    pushPriority(15);
    pushPriority(40);

    printNode();

    return 0;
}
