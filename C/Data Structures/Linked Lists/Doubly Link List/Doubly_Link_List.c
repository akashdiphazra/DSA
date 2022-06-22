// Link -->  https://www.cs.cmu.edu/~guna/15-123S11/Lectures/Lecture11.pdf
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *prev;
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
struct node *delete_before(struct node *);
struct node *delete_doubly_link_list(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n******* DOUBLY LINK LIST *******");
        printf("\n1.  Create Doubly Link List: ");
        printf("\n2.  Display Doubly Link List: ");
        printf("\n3.  Insert the node at the begining: ");
        printf("\n4.  Insert the node at the end: ");
        printf("\n5.  Add a node before a given node: ");
        printf("\n6.  Add a node after a given node: ");
        printf("\n7.  Delete a node from the begining: ");
        printf("\n8.  Delete a node from the end: ");
        printf("\n9.  Delete a node after any given node: ");
        printf("\n10. Delete a node before any given node: ");
        printf("\n11. Delete entire Doubly Link List: ");
        printf("\n#Enter 12 to end the program: ");
        printf("\n#Enter your Choice: ");
        printf("\nakashdiphazra@root~faux:-# ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_list(start);
            printf("\nDOUBLY LINK LIST CREATED\n");
            break;

        case 2:
            printf("\nDOUBLY LINK LIST:\n\n");
            start = display(start);
            break;

        case 3:
            start = insert_beg(start);
            printf("\nNODE INSERTED SUCCESSFULLY AT THE BEGINING\n");
            break;

        case 4:
            start = insert_end(start);
            printf("\nNODE INSERTED SUCCESSFULLY AT THE END\n");
            break;

        case 5:
            start = insert_before(start);
            printf("\nNODE INSERTED SUCCESSFULLY\n");
            break;

        case 6:
            start = insert_after(start);
            printf("\nNODE INSERTED SUCCESSFULLY\n");
            break;

        case 7:
            start = delete_beg(start);
            printf("\nNODE DELETED SUCCESSFULLY FROM THE BEGINING\n");
            break;

        case 8:
            start = delete_end(start);
            printf("\nNODE DELETED SUCCESSFULLY FROM THE END\n");
            break;

        case 9:
            start = delete_after(start);
            printf("\nNODE DELETED SUCCESSFULLY\n");
            break;

        case 10:
            start = delete_before(start);
            printf("\nNODE DELETED SUCCESSFULLY\n");
            break;

        case 11:
            start = delete_doubly_link_list(start);
            printf("\nENTIRE DOUBLY LINK LIST DELETED SUCCESSFULLY\n");
            break;
        }
    } while (option != 12);
    return 0;
}

struct node *create_list(struct node *head)
{
    struct node *new_node, *ptr;
    int val;
    printf("\n Enter -1 to end the program: ");
    printf("\n Enter the data: ");
    scanf("%d", &val);
    while (val != -1)
    {
        if (head == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = val;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            ptr = head;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = val;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &val);
    }
    return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    int count = 0;
    ptr = head;
    if (head == NULL)
    {
        printf("WARNING : LINK LIST EMPTY\n");
        return head;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr == head)
            {
                printf("[NULL][HEAD %d]", ptr->data);
                ptr = ptr->next;
            }
            else
            {
                printf(" <---> [ %d ]", ptr->data);
                ptr = ptr->next;
            }
            count++;
        }
        if (ptr == NULL)
        {
            printf(" <--> NULL <--> ");
        }
        printf("\n\nSize of the Doubly Link List: %d\n", count);
    }
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node;
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    if (head == NULL)
    {
        printf("\nWARNING : DOUBLY LINK LIST IS EMPTY SO INSERTING NEW VALUE");
        new_node->prev = NULL;
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else if (head != NULL)
    {
        head->prev = new_node;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
    }
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *new_node, *ptr;
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    if (head == NULL)
    {
        printf("\nWARNING : DOUBLY LINK LIST IS EMPTY SO INSERTING NEW VALUE");
        new_node->prev = NULL;
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = NULL;
    }
    return head;
}

struct node *insert_before(struct node *head)
{
    struct node *ptr, *new_node;
    int num, val;
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the value from the node before which node has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = head;
    if (head == NULL)
    {
        printf("\nWARNING : DOUBLY LINK LIST IS EMPTY SO INSERTING NEW VALUE");
        new_node->prev = NULL;
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    // Boundary Condition
    else if (head->data == val && ptr->data == val)
    {
        new_node->prev = NULL;
        new_node->next = ptr;
        ptr->prev = new_node;
        head->prev = new_node;
        head = new_node;
        return head;
    }
    else
    {
        while (ptr->data != val && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->data != val && ptr->next == NULL)
        {
            printf("\nThe given node %d is not present in the list\n", val);
            return head;
        }
        else
        {
            new_node->next = ptr;
            new_node->prev = ptr->prev;
            ptr->prev->next = new_node;
            ptr->prev = new_node;
        }
    }
    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the value from the node after which node has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = head;
    if (head == NULL)
    {
        printf("\nWARNING : DOUBLY LINK LIST IS EMPTY SO INSERTING NEW VALUE");
        new_node->prev = NULL;
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else
    {
        while (ptr->data != val && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->data != val && ptr->next == NULL)
        {
            printf("\nThe given node %d is not present in the list\n", val);
            return head;
        }
        if (ptr->data == val && ptr->next == NULL)
        {
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
            return head;
        }
        else
        {
            new_node->prev = ptr;
            new_node->next = ptr->next;
            ptr->next->prev = new_node;
            ptr->next = new_node;
        }
    }
    return head;
}

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nWARNING : LINK LIST EMPTY");
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
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nWARNING : LINK LIST EMPTY");
        return head;
    }
    else if (head->data && ptr->data && ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
        return head;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
    return head;
}

struct node *delete_after(struct node *head)
{
    struct node *ptr, *temp;
    int val;
    printf("Enter the value from the node after which you want to delete: ");
    scanf("%d", &val);
    ptr = head;
    if (head == NULL)
    {
        printf("\nWARNING : LINK LIST EMPTY");
        return head;
    }
    else
    {
        while (ptr->data != val && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->data == val && ptr->next == NULL && head->data == val)
        {
            printf("\nONLY ONE ELEMENT IN THE LIST\n");
            head = NULL;
            free(ptr);
            return head;
        }
        else if (ptr->data == val && ptr->next == NULL)
        {
            printf("Not Possible NULL value after the node");
            return head;
        }
        else if (ptr->data != val && ptr->next == NULL)
        {
            printf("\nThe given node %d is not present in the list\n", val);
            return head;
        }
        else
        {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->prev = ptr;
            free(temp);
        }
    }
    return head;
}

struct node *delete_before(struct node *head)
{
    struct node *ptr, *temp;
    int val;
    printf("Enter the value from the node after which you want to delete: ");
    scanf("%d", &val);
    ptr = head;
    if (head == NULL)
    {
        printf("\nWARNING : LINK LIST EMPTY");
        return head;
    }
    else
    {
        while (ptr->data != val)
        {
            ptr = ptr->next;
        }
        if (ptr->data == val && ptr->next == NULL && head->data == val)
        {
            head = delete_beg(head);
            return head;
        }
        else if (ptr->data == val && ptr->next == NULL)
        {
            printf("Not Possible NULL value after the node");
            return head;
        }
        else
        {
            temp = ptr->prev;
            if (temp == head)
            {
                head = delete_beg(head);
                return head;
            }
            else
            {
                ptr->prev = temp->prev;
                temp->prev->next = ptr;
                free(temp);
            }
        }
    }
    return head;
}

struct node *delete_doubly_link_list(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nWARNING : LINK LIST EMPTY");
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
    }
    return head;
}
