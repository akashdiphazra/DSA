// https://www2.hawaii.edu/~walbritt/ics212/examples/linkedlist.c
// https://www.cs.cmu.edu/~guna/15-123S11/Lectures/Lecture11.pdf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 30

struct node
{
    char *data;
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
struct node *delete_linklist(struct node *);
struct node *reverse_linklist(struct node *);

int main()
{
    int option;
    char temp;
    do
    {
        printf("\n********** SINGLY LINK LIST ********** ");
        printf("\n1.  Create a Singly Link List: ");
        printf("\n2.  Display the Singly Link List: ");
        printf("\n3.  Insert node at the begining of the Link List: ");
        printf("\n4.  Insert node at the end of the Link List: ");
        printf("\n5.  Insert before any given node in the Link List: ");
        printf("\n6.  Insert after any given node in the Link List: ");
        printf("\n7.  Delete the node from the begining: ");
        printf("\n8.  Delete the node at the end: ");
        printf("\n9.  Delete the node after any given node in the Link List: ");
        printf("\n10. Delete the entire the Link List: ");
        printf("\n11. Reverse Link List: ");
        printf("\n#Enter 12 to end the program: ");
        printf("\nakashdiphazra@root~faux:-# ");
        scanf("%d", &option);
        scanf("%[^\n]", &temp);
        switch (option)
        {
        case 1:
            start = create_list(start);
            printf("\nSINGLY LINK LIST CREATED\n");
            break;

        case 2:
            start = display(start);
            break;

        case 3:
            start = insert_beg(start);
            printf("\nNODE INSERTED AT THE BEGINING OF THE LIST\n");
            break;

        case 4:
            start = insert_end(start);
            printf("\nNODE INSERTED AT THE END OF THE LIST\n");
            break;

        case 5:
            start = insert_before(start);
            printf("\nNODE INSERTED SUCESSFULLY\n");
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
            start = delete_linklist(start);
            printf("\nLINK LIST DELETED SUCESSFULLY\n");
            break;

        case 11:
            start = reverse_linklist(start);
            printf("\nLINK LIST REVERSED SUCESSFULLY\n");
            break;
        }
    } while (option != 12);
    return 0;
}

struct node *create_list(struct node *head)
{
    struct node *new_node, *ptr;
    char str[MAX] = {'\0'};
    char temp;
    printf("\nPlease Enter quit to END (if you don't want to continue)");
    printf("\nEnter any string data: ");
    scanf("%c", &temp);
    scanf(" %[^\n]s", str);
    // scanf("%[^\n]%*c", str);
    // scanf("%10[0-9a-zA-Z]", str);
    while (strcmp(str, "quit") != 0)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = malloc(strlen(str) + 1);
        strcpy((char *)(new_node->data), str);
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
        printf("\nEnter any string data: ");
        scanf("%c", &temp);
        scanf(" %[^\n]s", str);
        // scanf("%10[0-9a-zA-Z]", str);
        // scanf("%[^\n]%*c", str);
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
    }
    else
    {
        ptr = head;
        printf("\n _____________ SINGLY LINK LIST _____________ \n\n");
        while (ptr != NULL)
        {
            if (ptr == head)
            {
                printf("[HEAD] %s --> ", ptr->data);
                ptr = ptr->next;
            }
            else
            {
                printf("%s --> ", ptr->data);
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
    char str[MAX] = {'\0'};
    printf("\nEnter any string data: ");
    scanf(" %[^\n]s", str);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = malloc(strlen(str) + 1);
    strcpy((char *)(new_node->data), str);
    new_node->next = head;
    head = new_node;
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *new_node, *ptr;
    char str[MAX] = {'\0'};
    printf("Enter any string data: ");
    scanf(" %[^\n]s", str);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = malloc(strlen(str) + 1);
    strcpy((char *)(new_node->data), str);
    new_node->next = NULL;
    if (head == NULL)
    {
        printf("\nWARNING: LINK LIST EMPTY");
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
    char str[MAX] = {'\0'}, match[MAX] = {'\0'}, permission[MAX] = {'\0'}; // Permissiong for boundary conditions

    printf("\nEnter any string data: ");
    scanf(" %[^\n]s", str);
    printf("\nEnter the data from the node before which the data has to be inserted: ");
    scanf(" %[^\n]s", match);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = malloc(strlen(str) + 1);
    strcpy((char *)(new_node->data), str);
    ptr = head;

    // Boundary Condition
    if (head == NULL)
    {
        printf("\nWARNING: The node is empty so inserting new value to the node ");
        printf("\nDo you want to insert a new value: ");
        scanf(" %[^\n]s", permission);
        if (strcmp(permission, "yes") == 0)
        {
            head = new_node;
            new_node->next = NULL;
        }
        else
        {
            return head;
        }
    }
    // Boundary Condition
    else if (strcmp(ptr->data, match) == 0)
    {
        head = new_node;
        new_node->next = ptr;
        return head;
    }
    else
    {
        while (strcmp(ptr->data, match) != 0 && ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        // Boundary Condition
        if (strcmp(ptr->data, match) != 0 && ptr->next == NULL)
        {
            printf("\nThe given number not found in the link list");
            return head;
        }
        else
        {
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }
    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    char str[MAX] = {'\0'}, match[MAX] = {'\0'}, permission[MAX] = {'\0'}; // Permissiong for boundary conditions

    printf("\nEnter any string data: ");
    scanf(" %[^\n]s", str);
    printf("\nEnter the data from the node after which the data has to be inserted: ");
    scanf(" %[^\n]s", match);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = malloc(strlen(str) + 1);
    strcpy((char *)(new_node->data), str);
    ptr = head;
    preptr = ptr;
    if (head == NULL)
    {
        printf("\nWARNING: The node is empty so inserting new value to the node ");
        printf("\nDo you want to insert a new value: ");
        scanf(" %[^\n]s", permission);
        if (strcmp(permission, "yes") == 0)
        {
            head = new_node;
            new_node->next = NULL;
        }
        else
        {
            return head;
        }
    }
    else if (strcmp(preptr->data, match) == 0)
    {
        ptr = ptr->next;
        preptr->next = new_node;
        new_node->next = ptr;
    }
    else
    {
        while (strcmp(preptr->data, match) != 0 && preptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (strcmp(preptr->data, match) != 0 && preptr->next == NULL)
        {
            printf("\nThe given number not found in the link list\n");
            return head;
        }
        else
        {
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }
    return head;
}

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nWARNING: LINK LIST EMPTY\n");
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
        printf("\nWARNING: LINK LIST EMPTY\n");
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
    char match[MAX] = {'\0'};
    printf("Enter the data after which the node you want to delete: ");
    scanf(" %[^\n]s", match);
    ptr = head;
    preptr = ptr;
    if (head == NULL)
    {
        printf("\nWARNING: LINK LIST EMPTY");
        return head;
    }
    else if (strcmp(preptr->data, match) == 0 && preptr->next == NULL)
    {
        printf("\nNOT POSSLIBLE ONLY ONE ELEMENT IN THE LIST");
        return head;
    }
    else if (strcmp(preptr->data, match) == 0 && preptr->next->data && head->data)
    {
        ptr = ptr->next;
        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
    else
    {
        while (strcmp(preptr->data, match) != 0 && preptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (strcmp(preptr->data, match) == 0 && preptr->next == NULL)
        {
            printf("\nNOT POSSLIBLE");
            return head;
        }
        else if (strcmp(preptr->data, match) != 0 && preptr->next == NULL)
        {
            printf("\nThe given data not found in the link list\n");
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

struct node *delete_linklist(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nWARNING: LINK LIST EMPTY");
        return head;
    }
    else
    {
        while (head != NULL)
        {
            ptr = head;
            head = head->next;
            free(ptr);
        }
    }
    return head;
}

struct node *reverse_linklist(struct node *head)
{
    struct node *current, *prev, *next;
    next = NULL, prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
