#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* Create_Link_Node (Node* next, Node* prev, int value);

int main()
{
Node* list_ptr = (Node*) calloc (1, sizeof(Node));
list_ptr -> next = NULL;
list_ptr -> prev = NULL;
Create_Link_Node (list_ptr -> next, list_ptr -> prev, 10);

printf("%d", list_ptr -> data);

/*
int a = 0;
scanf("%d", &a);
printf("Meow %d\n", a);
printf("Meow \n");

*/
free (list_ptr);
return 0;
}

Node* Create_Link_Node (Node* next, Node* prev, int value)
{
    Node* new_n = (Node*) calloc (1, sizeof(Node));

    new_n -> data = value;
    new_n -> next = next;
    new_n -> prev = prev;
    next -> prev = new_n;
    prev -> next = new_n;

return new_n;
}
