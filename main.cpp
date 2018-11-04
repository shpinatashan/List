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

Node* Create_Node (int value);
Node* Insert_Node (Node* cur, int value);
Node* Search_Node (Node* cur, int value);
int   Indexx_Node (Node* cur);
void  Printf_Node (Node* list_ptr);
void  Delete_Node (Node* cur);
void  Swap___Node (Node* ptr1, Node* ptr2);



int main()
{
Node* list_ptr = Create_Node (4);
Node* cur = list_ptr;
int k = 0;
printf("Number of nodes ");
scanf("%d", &k);

for (int i = 0; i < k; i++)
{
    int num = 0;
    printf("a = ");
    scanf("%d", &num);
    cur = Insert_Node(cur, num);
}

int a = 0;
printf("Search ");
scanf("%d", &a);

Node* searches = Search_Node (list_ptr, a);
cur = searches;
if (cur == NULL) printf("shit\n");
int index = Indexx_Node (cur);
if (index != 0)
    printf("index = %d\n", index+1);

Node* tmp = list_ptr -> next;
//Swap___Node (cur, tmp);

Delete_Node (tmp);
printf("list: ");
Printf_Node (list_ptr);

free (list_ptr);
return 0;
}

Node* Create_Node (int value)
{
    Node* list_ptr = (Node*) calloc (1, sizeof(Node));

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;

return list_ptr;
}

Node* Insert_Node(Node* cur, int value)
{
    Node* new_n = (Node*) calloc (1, sizeof(Node));

    new_n -> data = value;
    new_n -> next = cur -> next;
    new_n -> prev = cur;
    cur   -> next = new_n;
    if (new_n -> next == NULL) return new_n;
    (new_n -> next) -> prev = new_n;

return new_n;
}

Node* Search_Node (Node* list_ptr, int value)
{
    Node* cur = list_ptr;

    while(cur != NULL)
    {
        if(cur -> data == value) return cur;
        cur = (cur -> next);
    }

return NULL;
}

int   Indexx_Node (Node* cur)
{
    if (cur == NULL) return 0;
    Node* tmp = cur;
    int counter = 0;

    while (cur -> prev != NULL)
    {
        counter ++;
        cur = (cur -> prev);
    }
if (counter == 0)
    printf("Sorry!There is no such element\n");
return counter;
}

void Printf_Node (Node* list_ptr)
{
    Node* p = list_ptr;

    printf("%d  ", p -> data);
    p = p -> next;
    while (p != NULL)
    {
    printf("%d ", p -> data);
    p = p -> next;
    }
}

void  Swap___Node (Node* ptr1, Node* ptr2)
{
    if ((ptr1 != NULL)&& (ptr2 != NULL))
{
    Node* tmp = (Node*) calloc (1, sizeof(Node));

    (tmp -> prev) = (ptr1 -> prev);
    (tmp -> next) = (ptr1 -> next);
    (tmp -> data) = (ptr1 -> data);

    if (ptr1 -> prev != NULL)
        (ptr1 -> prev) -> next = ptr2;
    if (ptr2 -> next != NULL)
        (ptr2 -> next) -> prev = ptr1;

    (ptr1 -> prev) = (ptr2 -> prev);
    (ptr1 -> next) = (ptr2 -> next);
    (ptr1 -> data) = (ptr2 -> data);

    (ptr2 -> prev) = (tmp -> prev);
    (ptr2 -> next) = (tmp -> next);
    (ptr2 -> data) = (tmp -> data);
}
}

void Delete_Node(Node* cur)
{
    (cur -> prev) -> next = (cur -> next);
    (cur -> next) -> prev = (cur -> prev);
free (cur);
}

