#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
using namespace std;

const int can = 3;

struct Node
{
    int can1;
    int data;
    Node* next;
    Node* prev;
    double checksum;
    int can2;
};

Node* Create_Node (int value);
Node* Insert_Node (Node* cur, int value);
Node* Search_Node (Node* cur, int value);
int   Indexx_Node (Node* cur, Node* list_ptr);
void  Delete_single_Node (Node* cur, Node* list_ptr);
void  Swap___Node (Node* ptr1, Node* ptr2);
int   OK_Node(Node* ptr);
void  Calculate_CHCKSM(Node* ptr);
void  Printf_Node (Node* list_ptr);

int main()
{
int number = 0, head = 0;
printf("Number of nodes ");
scanf("%d", &number);
if (number <= 0)
    {
        printf("invalid input");
        return -1;
    }

printf("Head ");
if (scanf("%d", &head) != 1)
    {
        printf("invalid input");
        return -1;
    }

Node* list_ptr = Create_Node (head);
if (list_ptr == NULL)
    {
        printf("NULL ptr");
        return -2;
    }
Node* cur = list_ptr;
for (int i = 1; i < number; i++)
{
    int num = 0;
    printf("a = ");
    if (scanf("%d", &num) != 1)
    {
        printf("invalid input");
        return -1;
    }
    cur = Insert_Node(cur, num);
    if (cur == NULL)
    {
        printf("NULL ptr");
        return -2;
    }
}

int value = 0;
printf("Search ");
if (scanf("%d", &value) != 1)
{
    printf("invalid input");
    return -1;
}

Node* searches = Search_Node (list_ptr, value);
    //находим индекс найденного узла
cur = searches;
int index = Indexx_Node (cur, list_ptr);
if (index > 0)
    printf("index = %d\n", index-1);

    //Ќайденный узел  ставим на место первого. ѕервый затем удал€етс€.
Node* tmp = list_ptr;
Swap___Node (cur, tmp);

if (cur == list_ptr)
    list_ptr = cur -> next;
Delete_single_Node (cur, list_ptr);


printf("\nlist: ");
Printf_Node (list_ptr);

return 0;
}

int OK_Node(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("ptr \n");
        return -21;
    }

    if ( ptr -> checksum != ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% 12978 ))
    {
        printf("CHKSUM\n");
        return -22;
    }
    if ( ptr -> can1 != can)
    {
        printf("can1\n");
        return -23;
    }

    if ( ptr -> can2 != can)
    {
        printf("can2\n");
        return -24;
    }

return 1;
}

void Calculate_CHCKSM(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("NULL ptr");
       return;
    }

    ptr -> checksum = ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% 12978 );
}

Node* Create_Node (int value)
{
    Node* list_ptr = (Node*) calloc (1, sizeof(Node));

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;
    list_ptr -> can1 = can;
    list_ptr -> can2 = can;

    Calculate_CHCKSM(list_ptr);
    if (OK_Node(list_ptr) < 0)
    {
      printf ("ERROR in Create_Node");
      return NULL;
    }

return list_ptr;
}

Node* Insert_Node(Node* cur, int value)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Insert_Node");
        return NULL;
    }
    Node* new_n = (Node*) calloc (1, sizeof(Node));

    new_n -> data = value;
    new_n -> next = cur -> next;
    new_n -> prev = cur;
    cur   -> next = new_n;
    new_n -> can1 = can;
    new_n -> can2 = can;
    Calculate_CHCKSM(new_n);
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }
    if (new_n -> next == NULL)
        return new_n;

    (new_n -> next) -> prev = new_n;
    new_n  -> can1 = can;
    new_n  -> can2 = can;
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }

return new_n;
}

Node* Search_Node (Node* list_ptr, int value)
{
    Calculate_CHCKSM(list_ptr);
    if (OK_Node(list_ptr) < 0)
    {
        printf ("ERROR in Search_Node\n");
        return NULL;
    }

    if (list_ptr -> data == value)
        return list_ptr;


    Node* cur = list_ptr;

    while(cur != NULL)
    {
        Calculate_CHCKSM(cur);
        if (OK_Node(cur) < 0)
        {
           printf ("ERROR search\n");
           return NULL;
        }

        if(cur -> data == value)
            return cur;
        cur = (cur -> next);
    }
    printf("Sorry!There is no such element \n");
return NULL;
}

int Indexx_Node (Node* cur, Node* list_ptr)
{
    if (cur == list_ptr)
        return 1;
    if (cur == NULL)
        return -1;
    Node* tmp = cur;
    int counter = 1;

    while (cur -> prev != NULL)
    {
        counter ++;
        cur = (cur -> prev);
    }
    if (counter == 1)
        printf("Sorry!There is no such element\n");
return counter;
}

void Printf_Node (Node* list_ptr)
{
    if (list_ptr == NULL)
    {
        printf ("Error in Printf_Node/The list is empty");
        return;
    }
    Node* p = list_ptr;

    printf("%d ", p -> data);
    p = p -> next;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
}

void Swap___Node (Node* ptr1, Node* ptr2)
{
    if ((ptr1 != NULL)&& (ptr2 != NULL))
    {
        int tmp;
        tmp = (ptr1 -> data);
        (ptr1 -> data) = (ptr2 -> data);
        (ptr2 -> data) = tmp;
        Calculate_CHCKSM(ptr1);
        Calculate_CHCKSM(ptr2);
        if (OK_Node(ptr1) < 0)
            printf ("ERROR ptr \n");
        if (OK_Node(ptr2) < 0)
            printf ("ERROR ptr \n");

    }
}

void Delete_single_Node(Node* cur, Node* list_ptr)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Delete_Node");
        return;
    }

    if (cur -> prev == NULL)
    {
        if (cur -> next == NULL)
        return ;
    }

    if (cur -> prev == NULL)
    {
        (cur -> next) -> prev = NULL;
        return;
    }
    if (cur -> next == NULL)
    {
        (cur -> prev) -> next = NULL;
        return;
    }
    (cur -> prev) -> next = (cur -> next);
    (cur -> next) -> prev = (cur -> prev);

    free (cur);
    cur = NULL;
}
