//WAP to understand doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* Head = NULL;
struct node *CreateNode(int ele)
{
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode -> data = ele;
    NewNode -> prev = NULL;
    NewNode -> next = NULL;
    return NewNode;
}
void insertNodeInBeg(int ele)
{
    struct node* NewNode = CreateNode(ele);
    if (Head = NULL)
    {
        Head = NewNode;
    }
    else
    {
        NewNode -> next = Head;
        Head -> prev = NewNode;
        Head = NewNode;   
    }
    printf("Node Inserted !!!\n");
}
void insertNodeAtEnd(int ele)
{
    struct node* NewNode = CreateNode(ele);
    if (Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        struct node* temp = Head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = NewNode;
        NewNode -> prev = temp;
    }
    printf("Node Inserted !!!\n");
}
void insertNodeAtAnyPosition(int ele, int position)
{
    if (Head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else if (position == 1)
    {
        insertNodeInBeg(ele);
    }
    else
    {
        int i = 1;
        struct node* temp = Head;
        while (i != position && temp != NULL)
        {
            temp = temp -> next;
            i++;
        }
        if (temp != NULL && position>0)
        {
            struct node* NewNode = CreateNode(ele);
            NewNode -> prev = temp -> prev;
            temp -> prev -> next = NewNode;
            NewNode -> next = temp;
            temp -> prev = NewNode;
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
    if (Head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else
    {
        struct node *temp = Head;
        Head = Head -> next;
        if (Head != NULL)
        {
            Head -> prev = NULL;
        }
        free(temp);
        printf("Node Deleted !!!\n");
    }
}
void deleteNodeFromEnd()
{
    if (Head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else
    {
        struct node *temp = Head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        if (temp -> prev != NULL)
        {
            temp -> prev -> next = NULL;
        }
        else
        {
            Head = NULL;
        }
        free(temp);
    }
    printf("Node Deleted !!!\n");
}
void deleteNodeFromAnyPosition(int position)
{
    if (Head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else if (position == 1)
    {
        deleteNodeFromBeg();
    }
    else
    {
        int i = 1;
        struct node* temp = Head;
        while (i != position && temp != NULL)
        {
            temp = temp -> next;
            i++;
        }
        if (temp != NULL && position>0)
        {
            temp -> prev -> next = temp -> next;
            if (temp -> next != NULL)
            {
                temp -> next -> prev = temp -> prev;
            }
            free(temp);
            printf("Node Deleted !!!\n");
        }
        else
        {
            printf("Invalid Position !!!\n");
        }
    }
}
void search(int target)
{
    if (Head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else
    {
        struct node *temp = Head;
        while (temp != NULL)
        {
            if (temp -> data == target)
            {
                printf("Found !!!\n");
                return;
            }
            temp = temp -> next;
        }
        printf("Not Found !!!\n");
    }
}
void display()
{
    if (Head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node* temp = Head;
        while (temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}
int main()
{
    while (1)
    {
        printf("------ Doubly Linked List ------\n");
        printf("1. Insert Node In Beginning\n");
        printf("2. Insert Node At End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Beginning\n");
        printf("5. Delete Node From End\n");
        printf("6. Delete Node From Any Position\n");
        printf("7. Search Element In List\n");
        printf("8. Display List\n");
        printf("9. Exit\n\n");
        int choice,value,pos;
        printf("Enter choice = ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value = ");
            scanf("%d",&value);
            insertNodeInBeg(value);
            break;
        case 2:
            printf("Enter Value = ");
            scanf("%d",&value);
            insertNodeAtEnd(value);
            break;
        case 3:
            printf("Enter Value = ");
            scanf("%d",&value);
            printf("Enter Position = ");
            scanf("%d",&pos);
            insertNodeAtAnyPosition(value,pos);
            break;
        case 4:
            deleteNodeFromBeg();
            break;
        case 5:
            deleteNodeFromEnd();
            break;
        case 6:
            printf("Enter Position = ");
            scanf("%d",&pos);
            deleteNodeFromAnyPosition(pos);
            break;
        case 7:
            printf("Enter Target = ");
            scanf("%d",&value);
            search(value);
            break;      
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid choice !!!\n");
            break;
        }
        printf("\n\n");
		system("pause");
    }
    return 0;
}  