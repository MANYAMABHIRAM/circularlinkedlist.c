#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *temp, *newnode, *tail, *temp1;
typedef struct node node;
void create()
{
    int value;
    printf("Enter data -1 to stop:");
    scanf("%d", &value);
    while (value != -1)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->data = value;
        newnode->next = NULL;
        if (!head)
        {
            newnode->next = newnode;
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        scanf("%d", &value);
    }
}
void display()
{
    temp = head;
    while (temp->next != head)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}
int Count_node()
{
    int count = 1;
    temp = head;
    if (!head)
        return 0;
    else
    {
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}
void Insert(int value, int pos)
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    int count = Count_node();
    if (pos == 1)
    {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
    else if (pos == count + 1)
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos - 2; i++)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void Delete(int pos)
{
    int count = Count_node();
    if (pos == 1)
    {
        head = head->next;
        tail->next = head;
    }
    else if (pos == count)
    {
        temp = head;
        while (temp->next != tail)
            temp = temp->next;
        temp->next = temp->next->next;
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos - 2; i++)
            temp = temp->next;
        temp->next = temp->next->next;
    }
}
void sort()
{
    int i, j, t;
    temp = head;
    do
    {
        temp1 = temp->next;
        while (temp1 != head)
        {
            if (temp->data > temp1->data)
            {
                t = temp->data;
                temp->data = temp1->data;
                temp1->data = t;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    } while (temp != head);
}
void sort_insert(int value)
{
    sort();
    temp = head;
    if (temp->data >= value)
        Insert(value, 1);
    else if (tail->data <= value)
        Insert(value, Count_node() + 1);
    else
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->data = value;
        newnode->next = NULL;
        while (temp->next != head)
        {
            if (temp->next->data >= value)
            {
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            temp = temp->next;
        }
    }
}
void Del_ele(int value)
{
    if (head->data == value)
        Delete(1);
    else if (tail->data == value)
        Delete(Count_node());
    else
    {
        int flag = 0, pos = 1;
        temp = head;
        while (temp->next != head)
        {
            if (temp->data == value)
            {
                flag = 1;
                break;
            }
            pos++;
            temp = temp->next;
        }
        if (flag)
            Delete(pos);
        else
            printf("\nNo element found");
    }
}
void delDup()
{
    temp = head;
    do
    {
        temp1 = temp->next;
        while (temp1 != head)
        {
            if (temp1->data == temp->data)
            {
                temp->next = temp1->next;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    } while (temp != head);
}
void mid_Ele()
{
    sort();
    int count = Count_node();
    int n = count / 2;
    temp = head;
    if (count % 2 == 0)
    {
        n--;
    }
    for (int i = 0; i < n; i++)
        temp = temp->next;
    printf("\n%d", temp->data);
}
void rev_node()
{
    node *prev = NULL;
    node *current = head;
    node *n;
    do
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    } while (current != head);
    head->next = prev;
    head = prev;
}
void detect_Cycle()
{
    temp = head;
    int flag = 0;
    do
    {
        if (temp->next == head)
            flag = 1;
        temp = temp->next;
    } while (temp != head);
    if (flag)
        printf("\nCycle is detected");
    else
        printf("\nNo cycle is detected");
}
int main()
{
    int ch, pos, ele;
    while (1)
    {
        printf("\n1-Create\n2-Display\n3-Insert\n4-Deletion\n5-Sort\n6-Inserting at appropriate position\n7-Delete based on value\n8-Deletion of Duplicates\n9-Delete node from end\n10-Middle element\n11-Reverse\n12-Detection of Cycle\n13-Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nEnter position and element:");
            scanf("%d %d", &pos, &ele);
            Insert(ele, pos);
            break;
        case 4:
            printf("Enter position to delete:");
            scanf("%d", &pos);
            Delete(pos);
            break;
        case 5:
            sort();
            break;
        case 6:
            printf("Enter element:");
            scanf("%d", &ele);
            sort_insert(ele);
            break;
        case 7:
            printf("Enter element:");
            scanf("%d", &ele);
            Del_ele(ele);
            break;
        case 8:
            delDup();
            break;
        case 9:
            printf("\nEnter position:");
            scanf("%d", &pos);
            Delete(Count_node() - pos + 1);
            break;
        case 10:
            mid_Ele();
            break;
        case 11:
            rev_node();
            break;
        case 12:
            detect_Cycle();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
