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
void  Delete_single_Node (Node* cur);
void  Swap___Node (Node* ptr1, Node* ptr2);
void  Calculate_CHCKSM (Node* ptr);
void  Printf_Node (Node* list_ptr);
void  Delete_List (Node* list_ptr);

#include "list.cpp"
