int OK_Node(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("ptr \n");
        return ERR_NULL_Ptr;
    }
    #ifndef List_Fast
    if ( ptr -> checksum != ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% 12978 ))
    {
        printf("CHKSUM\n");
        return ERR_Chksum;
    }
    if ( ptr -> can1 != can)
    {
        printf("can1\n");
        return ERR_Can1;
    }

    if ( ptr -> can2 != can)
    {
        printf("can2\n");
        return ERR_Can2;
    }
    #endif
return OKK;
}

#ifndef List_Fast
void Calculate_CHCKSM(Node* ptr)
{
    if (ptr == NULL)
    {
        printf("NULL ptr chksum ");
       return;
    }

    ptr -> checksum = ( ((unsigned long long int) (ptr -> next) + (unsigned long long int)(ptr -> prev ) )% 12978 );
}
#endif
Node* Create_Node (int value)
{
    Node* list_ptr = (Node*) calloc (1, sizeof(Node));

    list_ptr -> next = NULL;
    list_ptr -> prev = NULL;
    list_ptr -> data = value;
    #ifndef List_Fast
    list_ptr -> can1 = can;
    list_ptr -> can2 = can;

    Calculate_CHCKSM(list_ptr);
    #endif
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
    #ifndef List_Fast
    new_n -> can1 = can;
    new_n -> can2 = can;
    Calculate_CHCKSM(new_n);
    #endif
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }
    if (new_n -> next == NULL)
        return new_n;

    (new_n -> next) -> prev = new_n;
    #ifndef List_Fast
    new_n  -> can1 = can;
    new_n  -> can2 = can;
    #endif
    if (OK_Node(new_n) < 0)
    {
        printf ("ERROR in Insert_Node\n");
        return NULL;
    }

return new_n;
}

Node* Search_Node (Node* list_ptr, int value)
{
    #ifndef List_Fast
    Calculate_CHCKSM(list_ptr);
    #endif
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
	#ifndef List_Fast
        Calculate_CHCKSM(cur);
	#endif
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
    if ((ptr1 != NULL) && (ptr2 != NULL))
    {
        int tmp;
        tmp = (ptr1 -> data);
        (ptr1 -> data) = (ptr2 -> data);
        (ptr2 -> data) = tmp;
	#ifndef List_Fast
        Calculate_CHCKSM(ptr1);
        Calculate_CHCKSM(ptr2);
	#endif
        if (OK_Node(ptr1) < 0)
            printf ("ERROR ptr \n");
        if (OK_Node(ptr2) < 0)
            printf ("ERROR ptr \n");
    }
    else
    {
	printf("PtrError in Swap\n ");
	return;
    }
}

void Delete_single_Node(Node* cur)
{
    if (OK_Node(cur) < 0)
    {
        printf ("Error in Delete_Node");
        return;
    }

    if (cur -> prev == NULL)
    {
        if (cur -> next == NULL)
        {
            free (cur);
            cur = NULL;
            return ;
        }
    }

    if (cur -> prev == NULL)
    {
        (cur -> next) -> prev = NULL;
        free (cur);
        cur = NULL;
        return;
    }
    if (cur -> next == NULL)
    {
        (cur -> prev) -> next = NULL;
        free (cur);
        cur = NULL;
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
        list_ptr = list_ptr -> next;
        free(tmp);
        tmp -> next = NULL;
        tmp = NULL;
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
	if (list_ptr -> next == NULL)
	{
		return NULL;
	} 
        list_ptr = list_ptr -> next;
    }
    #ifndef List_Fast
    Calculate_CHCKSM(list_ptr);
    #endif
return list_ptr;
}
