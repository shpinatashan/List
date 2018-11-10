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
Node* Ptr_index_Node (Node* list_ptr, int index);
int   Indexx_Node (Node* cur, Node* list_ptr);
int   OK_Node (Node* ptr);
void  Delete_single_Node (Node* cur, Node* list_ptr);
void  Swap___Node (Node* ptr1, Node* ptr2);
void  Calculate_CHCKSM (Node* ptr);
void  Printf_Node (Node* list_ptr);
void  Delete_List (Node* list_ptr);



int main()
{
    //creating a list
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
}
    //The function returns a ptr to the node with the number you inputted
int value = 0;
printf("Search ");
if (scanf("%d", &value) != 1)
{
    printf("invalid input");
    return -1;
}
Node* searches = Search_Node (list_ptr, value);

    //The function finds the index of the found node
cur = searches;
int index = Indexx_Node (cur, list_ptr);
if (index > 0)
    printf("index = %d\n", index-1);

    //swap two nodes.Find node by index
printf("enter two indexes\n");
int ind1 = 0, ind2 = 0;
scanf("%d %d", &ind1, &ind2);
Node* pr1 = Ptr_index_Node(list_ptr, ind1);
Node* pr2 = Ptr_index_Node(list_ptr, ind2);
Swap___Node (pr1, pr2);

    ////delete single node.Find node by index
printf("enter the index for the node to be removed\n");
int indel;
scanf("%d", &indel);
cur = Ptr_index_Node(list_ptr, indel);
if (cur == list_ptr)
    list_ptr = cur -> next;
Delete_single_Node (cur, list_ptr);

printf("\nlist: ");
Printf_Node (list_ptr);

Delete_List(list_ptr);

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
        printf("NULL ptr chksum ");
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
    free(p);
    p = NULL;
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


void  Delete_List (Node* list_ptr)
{
    if (list_ptr == NULL)
    {
        printf ("Error in Delete_List/The list is empty");
        return;
    }
    Node* tmp = list_ptr;
    while (list_ptr != NULL)
    {
        tmp = list_ptr;
        free(tmp);
        tmp -> next = NULL;
        tmp = NULL;
        list_ptr = list_ptr -> next;
    }
}


Node* Ptr_index_Node (Node* list_ptr, int index)
{
    if (OK_Node(list_ptr) < 0)
    {
        printf ("Error in Ptr_index_Node");
        return NULL;
    }

    for(int i = 0; i < index; i++)
    {
        list_ptr = list_ptr -> next;
    }
    Calculate_CHCKSM(list_ptr);

return list_ptr;
}
