#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int ele)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ele;
    temp->next = temp;
    return temp;
}

void insertNodeInBeg(int ele)
{
    struct Node *newNode = createNode(ele);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        head = newNode;
    }
    printf("Node Inserted !!!\n");
}

void insertNodeAtEnd(int ele)
{
    struct Node *newNode = createNode(ele);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    printf("Node Inserted !!!\n");
}

void insertNodeAtAnyPos(int pos, int ele)
{
    if (head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else if (pos == 1)
    {
        insertNodeInBeg(ele);
    }
    else
    {
        struct Node *newNode = createNode(ele);
        struct Node *temp = head;
        int i = 1;
        while (i != pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next != head || pos == i + 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted !!!\n");
        }
        else
        {
            printf("Invalid Position !!!\n");
        }
    }
}

void deleteNodeFromBeg()
{
    if (head == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else
    {
        struct Node *temp = head;
        if (head->next == head)
        { 
            head = NULL;
        }
        else
        {
            
            struct Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        }
        free(temp);
        printf("Node deleted !!!\n");
    }
}

void deleteNodeFromEnd()
{
    if (head == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        { 
            head = NULL;
        }
        else
        {
            prev->next = head;
        }
        free(temp);
        printf("Node deleted !!!\n");
    }
}

void deleteNodeFromAnyPos(int pos)
{
    if (head == NULL)
    {
        printf("List is Empty !!\n");
    }
    else if (pos == 1)
    {
        deleteNodeFromBeg();
    }
    else
    {
        int i = 1;
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (i != pos && temp->next != head)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (temp != head || (temp == head && i == pos))
        {
            prev->next = temp->next;
            free(temp);
            printf("Node deleted !!!\n");
        }
        else
        {
            printf("Invalid position !!\n");
        }
    }
}

void search(int target)
{
    if (head == NULL)
    {
        printf("List is empty !!!\n");
    } 
    else
    {
        struct Node *temp = head;
        do
        {
            if (temp->data == target)
            {
                printf("Element found!!!\n");
                return;
            }
            temp = temp->next;
        } while (temp != head);
        printf("Element not found !!!\n");
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty !!!!\n");
    }
    else
    {
        struct Node *temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        printf("------Circular Singly Linked List------\n");
        printf("1. Insert Node In Beginning\n");
        printf("2. Insert Node At End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Beginning\n");
        printf("5. Delete Node From End\n");
        printf("6. Delete Node From Any Position\n");
        printf("7. Search element in list\n");
        printf("8. Display list\n");
        printf("9. Exit\n");

        int choice, pos, value;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertNodeInBeg(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertNodeAtEnd(value);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);
            insertNodeAtAnyPos(pos, value);
            break;
        case 4:
            deleteNodeFromBeg();
            break;
        case 5:
            deleteNodeFromEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteNodeFromAnyPos(pos);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Choice!!!!!!\n");
        }
    }
    return 0;
}