//#define List_Fast

#include "list.h"

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
Delete_single_Node (cur);

printf("\nlist: ");
Printf_Node (list_ptr);

Delete_List(list_ptr);

return 0;
}
