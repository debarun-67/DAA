#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
int main()
{
    int choice = 0;
    while (choice != 8)
    {
        printf("Choose from the menu : \n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");
        printf("\nEnter your choice ->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
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
void beginsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;

        if (head == NULL)
        {
            ptr->next = ptr;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("\nNode inserted");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = ptr;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nNode inserted");
    }
}
void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                printf("\nCan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted");
    }
}
void begin_delete()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        free(ptr);
        printf("\nNode deleted from the beginning...\n");
    }
}
void last_delete()
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nOnly node of the list deleted...\n");
    }
    else
    {
        temp = head;
        prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
        printf("\nDeleted node from the end...\n");
    }
}
void random_delete()
{
    struct node *temp, *prev;
    int loc, i;
    printf("\nEnter the location of the node after which you want to perform deletion: ");
    scanf("%d", &loc);
    temp = head;
    prev = NULL;
    for (i = 0; i < loc; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == head)
        {
            printf("\nCan't delete\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    printf("\nDeleted node at location %d\n", loc);
}
void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\nPrinting values.\n");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}