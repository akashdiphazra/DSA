// https://www.usna.edu/Users/cs/wcbrown/courses/F14IC210/lec/l34/lec.html
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
struct node *reverse_list(struct node *);
struct node *remove_duplicates(struct node *);

void search_node(struct node *);
void middle_linklist(struct node *);

int main()
{
    int option;
    char temp;
    do
    {
        printf("\n\n ************** Singly Link List ************** ");
        printf("\n1.  Create a  Singly Link List ");
        printf("\n2.  Display a singly Link List ");
        printf("\n3.  Insert a node at the begining: ");
        printf("\n4.  Insert a node at the end: ");
        printf("\n5.  Insert before any given node: ");
        printf("\n6.  Insert after any given node: ");
        printf("\n7.  Delete node from the begining: ");
        printf("\n8.  Delete node from the end: ");
        printf("\n9.  Delete after any given node in the Link List: ");
        printf("\n10. Delete the Entire Link List: ");
        printf("\n11. Sort the entire Link List: ");
        printf("\n12. Reverse the Link List: ");
        printf("\n13. Remove duplicates from the Link List: ");
        printf("\n14. Search for a particular node in the Link List: ");
        printf("\n15. Print the middle of the Link List: ");
        printf("\n16. Enter 16 to End the program: ");
        printf("\nakashdiphazra@terminal:-$ ");
        scanf("%d", &option);
        scanf("%[^\n]", &temp);
        switch (option)
        {
        case 1:
            start = create_list(start);
            printf("\nLINK LIST CREATED ");
            break;

        case 2:
            start = display(start);
            break;

        case 3:
            start = insert_beg(start);
            printf("\nNODE INSERTED AT THE BEGINING");
            break;

        case 4:
            start = insert_end(start);
            printf("\nNODE INSERTED AT THE END");
            break;

        case 5:
            start = insert_before(start);
            printf("\nNODE INSERTED SUCESSFULLY");
            break;

        case 6:
            start = insert_after(start);
            printf("\nNODE INSERTED SUCESSFULLY\n");
            break;

        case 7:
            start = delete_beg(start);
            printf("\nNODE DELETED SUCESSFULLY\n");
            break;

        case 8:
            start = delete_end(start);
            printf("\nNODE DELETED SUCESSFULLY\n");
            break;

        case 9:
            start = delete_after(start);
            printf("\nNODE DELETED SUCESSFULLY\n");
            break;

        case 10:
            start = delete_list(start);
            printf("\nENTIRE LINK LIST DELETED SUCESSFULLY\n");
            break;

        case 11:
            start = sort_list(start);
            printf("\nLINK LIST SORTED\n");
            break;

        case 12:
            start = reverse_list(start);
            printf("\nLINK LIST REVERSED\n");
            break;

        case 13:
            start = remove_duplicates(start);
            printf("\nLINK LIST PREPROCESSED AND CLEANED\n");
            break;

        case 14:
            search_node(start);
            break;

        case 15:
            middle_linklist(start);
            break;
        }
    } while (option != 16);
    return 0;
}

struct node *create_list(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nPlease Enter -1 to END (if you don't want to continue)");
    printf("\nEnter any integer data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\nEnter any integer data: ");
        scanf("%d", &num);
    }
    return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    int count = 0;
    if (head == NULL)
    {
        printf("\nWARNING: THE LINK LIST IS EMPTY\n");
        return head;
    }
    else
    {
        ptr = head;
        printf("\n _____________ SINGLY LINK LIST _____________ \n\n");
        while (ptr != NULL)
        {
            if (ptr == head)
            {
                printf("[HEAD] %d --> ", ptr->data);
                ptr = ptr->next;
            }
            else
            {
                printf("%d --> ", ptr->data);
                ptr = ptr->next;
            }
            count++;
        }
        if (ptr == NULL)
        {
            printf("NULL");
        }
        printf("\nSize of the Link List: %d\n", count);
    }
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node;
    int num;
    printf("Enter any integer data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = head;
    head = new_node;
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *ptr, *new_node;
    int num;
    printf("Enter any interger data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head;
}

struct node *insert_before(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter any integer value: ");
    scanf("%d", &num);
    printf("\nEnter the data from the node before which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = head;
    // Boundary Condition
    if (head == NULL)
    {
        printf("\nWARNING: The node is empty so inserting new value to the node ");
        head = new_node;
        new_node->next = NULL;
    }
    // Boundary Condition
    else if (val == ptr->data)
    {
        head = new_node;
        new_node->next = ptr;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            // Boundary Condition
            if (ptr->next == NULL && ptr->data != val)
            {
                printf("\nThe given number not found in the link list");
                return head;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }
    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter any integer value: ");
    scanf("%d", &num);
    printf("\nEnter the data from the node after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = head;
    preptr = ptr;
    if (head == NULL)
    {
        printf("\nWARNING: The node is empty so inserting new value to the node\n");
        head = new_node;
        new_node->next = NULL;
        return head;
    }
    else if (preptr->data == val)
    {
        ptr = ptr->next;
        preptr->next = new_node;
        new_node->next = ptr;
        return head;
    }
    else
    {
        while (preptr->data != val)
        {
            preptr = ptr;
            if (preptr->next == NULL && preptr->data != val)
            {
                printf("\nThe given number not found in the link list\n");
                return head;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }
    return head;
}

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nWARNING: THE LINK LIST EMPTY");
        return head;
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node *ptr, *preptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nWARNING: THE LINK LIST EMPTY");
        return head;
    }
    else if (ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
    return head;
}

struct node *delete_after(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("Enter the data after which the node you want to delete: ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    if (head == NULL)
    {
        printf("\nWARNING: LINK LIST EMPTY");
        return head;
    }
    else if (preptr->data == val && head->data && preptr->next == NULL)
    {
        printf("\nNOT POSSLIBLE ONLY ONE ELEMENT IN THE LIST");
        return head;
    }
    else if (preptr->data == val && preptr->next->data && head->data)
    {
        ptr = ptr->next;
        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
    else
    {
        while (preptr->data != val && preptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr->data == val && preptr->next == NULL)
        {
            printf("\nNOT POSSLIBLE");
            return head;
        }
        else if (preptr->data != val && preptr->next == NULL)
        {
            printf("\nThe given number %d not found in the link list\n", val);
            return head;
        }
        else
        {
            preptr->next = ptr->next;
            free(ptr);
        }
    }
    return head;
}

struct node *delete_list(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nWARNING: LINK LIST EMPTY");
        return head;
    }
    else
    {
        ptr = head;
        while (head != NULL)
        {
            head = head->next;
            free(ptr);
            ptr = head;
        }
        head = NULL;
    }
    return head;
}

struct node *sort_list(struct node *head)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    if (head == NULL)
    {
        printf("\nLINK LIST EMPTY");
        return head;
    }
    else
    {
        while (ptr1->next != NULL)
        {
            ptr2 = ptr1->next;
            while (ptr2 != NULL)
            {
                if (ptr1->data > ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
    return head;
}

struct node *reverse_list(struct node *head)
{
    struct node *prevptr, *nextptr, *currentptr;
    if (head == NULL)
    {
        printf("WARNING: LINK LIST EMPTY AND IT CANNOT BE REVESRED");
        return head;
    }
    else
    {
        currentptr = head;
        prevptr = NULL;
        nextptr = NULL;
        while (currentptr != NULL)
        {
            nextptr = currentptr->next;
            currentptr->next = prevptr;
            prevptr = currentptr;
            currentptr = nextptr;
        }
        head = prevptr;
    }
    return head;
}

struct node *remove_duplicates(struct node *head)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

void search_node(struct node *head)
{
    struct node *ptr;
    int val, count = 1;
    printf("\nEnter the value of the node that needs to be searched in the Link List: ");
    scanf("%d", &val);
    if (head == NULL)
    {
        printf("\nWARNING: THE LINK LIST IS EMPTY");
        return;
    }
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("\nThe value %d present in the %d node of the Link List ", val, count);
            return;
        }
        else if (ptr->data != val && ptr->next == NULL)
        {
            printf("\nSorry!! The given value %d cannot be found in the Link List ", val);
            return;
        }
        else
        {
            ptr = ptr->next;
        }
        count++;
    }
}

void middle_linklist(struct node *head)
{
    struct node *slow_ptr, *fast_ptr;
    int count = 1;
    if (head == NULL)
    {
        printf("\nWARNING: THE LINK LIST IS EMPTY");
        return;
    }
    else
    {
        slow_ptr = head;
        fast_ptr = head;
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }
    struct node *ptr;
    ptr = slow_ptr;
    printf("\nMIDDLE OF THE LINK LIST:\n");
    while (ptr != NULL)
    {
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    if (ptr == NULL)
    {
        printf(" NULL");
    }
    printf("\nThe size of the Link List: %d", count);
}
