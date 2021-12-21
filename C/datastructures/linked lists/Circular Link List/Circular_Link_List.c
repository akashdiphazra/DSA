#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_circular_link_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_circular_link_list(struct node *);
struct node *delete_circular_link_list(struct node *);

int main()
{
    int option;
    char temp;
    do
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the begining");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node at the begining");
        printf("\n 6: Delete a node at the end");
        printf("\n 7: Delete a node after any given node");
        printf("\n 8: Delete entire circular link list");
        printf("\n 9: End");
        printf("\nakashdiphazra@terminal:-$ ");
        scanf("%d", &option);
        scanf("%[^\n]", &temp);
        switch (option)
        {
        case 1:
            start = create_circular_link_list(start);
            printf("\nCircular Link List Created");
            break;

        case 2:
            start = display(start);
            break;

        case 3:
            start = insert_beg(start);
            printf("\nNode inserted sucessfully at the beginning");
            break;

        case 4:
            start = insert_end(start);
            printf("\nNode inserted sucessfully at the end");
            break;

        case 5:
            start = delete_beg(start);
            printf("\nNode deleted sucessfully from the begining");
            break;

        case 6:
            start = delete_end(start);
            printf("\nNode deleted sucessfully from the begining");
            break;

        case 7:
            start = delete_after(start);
            printf("\nNode deleted sucessfully");
            break;

        case 8:
            start = delete_circular_link_list(start);
            printf("\nEntire circular link list deleted sucessfully ");
            break;
        }
    } while (option != 9);
    return 0;
}

struct node *create_circular_link_list(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    char temp;
    printf("Enter any integer data(type -1 to end): ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (head == NULL)
        {
            new_node->next = new_node;
            head = new_node;
        }
        else
        {
            ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = head;
        }
        printf("Enter any integer data(type -1 to end): ");
        scanf("%d", &num);
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
        printf("\nLINK LIST EMPTY");
        return head;
    }
    else
    {
        do
        {
            if (head->data && head->next == head)
            {
                break;
            }
            printf("%d ", ptr->data);
            ptr = ptr->next;
            count++;
        } while (ptr->next != head);
        count++;
        printf("%d ", ptr->data);
        printf("\nSize of the Circular Link List: %d", count);
    }
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter any integer value: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = head;
        head = new_node;
    }
    return head;
};

struct node *insert_end(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter any integer value: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = head;
    }
    return head;
};

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nLINK LIST EMPTY");
        return head;
    }
    else if (head->data && head->next == head)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
    }
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nLINK LIST EMPTY");
        return head;
    }
    else if (head->data && head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return head;
}

struct node *delete_after(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value after which the node has to be deleted: ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    if (head == NULL)
    {
        printf("\nLINK LIST EMPTY");
        return head;
    }
    if (preptr->data == val && preptr->next != head && head->data == val && head->data)
    {
        preptr = preptr->next->next;
        ptr = ptr->next;
        head->next = preptr;
        free(ptr);
        return head;
    }
    else if (preptr->data == val && preptr->next == head && head->data == val && head->data)
    {
        printf("\nNot Possible only one element in the circular link list");
        return head;
    }
    else
    {
        while (preptr->data != val && preptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr->data == val && preptr->next == head)
        {
            printf("\nLast element of the list not possible");
            return head;
        }
        if (preptr->next == head && preptr->data != val)
        {
            printf("\nThe given data %d cannot found in the circular link list", val);
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

struct node *delete_circular_link_list(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        head = delete_end(head);
    }
    free(head);
    head = NULL;
    return head;
}
