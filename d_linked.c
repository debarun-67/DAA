#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory allocation failed.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void beginsert(int data)
{
    struct node *newnode = createnode(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("\nnode inserted at the beginning.\n");
}
void lastinsert(int data)
{
    struct node *newnode = createnode(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("\nnode inserted at the end.\n");
}
void randominsert(int data, int loc)
{
    struct node *newnode = createnode(data);
    if (loc < 1)
    {
        printf("\nInvalid location for insertion.\n");
        return;
    }
    if (loc == 1)
    {
        newnode->next = head;
        if (head != NULL)
        {
            head->prev = newnode;
        }
        head = newnode;
        printf("\nnode inserted at a random location.\n");
        return;
    }
    struct node *temp = head;
    int count = 1;
    while (count < loc - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("\nInvalid location for insertion.\n");
        return;
    }
    newnode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
    printf("\nnode inserted at a random location.\n");
}
void begin_delete()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        printf("\nnode deleted from the beginning.\n");
    }
}
void last_delete()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            head = NULL;
        }
        free(temp);
        printf("\nnode deleted from the end.\n");
    }
}
void random_delete(int loc)
{
    if (head == NULL || loc < 1)
    {
        printf("\nList is empty or invalid location for deletion.\n");
        return;
    }
    struct node *temp = head;
    int count = 1;
    while (count < loc && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid location for deletion.\n");
        return;
    }
    struct node *delnode = temp->next;
    temp->next = delnode->next;
    if (delnode->next != NULL)
    {
        delnode->next->prev = temp;
    }
    free(delnode);
    printf("\nnode deleted after the specified location.\n");
}
void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nPrinting values...\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("Choose from the menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete node after specified location\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            int val;
            scanf("%d", &val);
            beginsert(val);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            lastinsert(val);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter location: ");
            int loc;
            scanf("%d", &loc);
            randominsert(val, loc);
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            printf("Enter location: ");
            scanf("%d", &loc);
            random_delete(loc);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}