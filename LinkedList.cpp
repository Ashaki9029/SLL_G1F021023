#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
};

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->info << " ";
        n = n->next;
    }
    cout << endl;
}

void createList(node **head)
{
    node *first = new node();
    node *mid = new node();
    node *last = new node();

    first->info = 30;
    first->next = mid;
    mid->info = 40;
    mid->next = last;
    last->info = 50;
    last->next = NULL;

    (*head) = first;
    printList(first);
}

void insertFirst(node **head, int temp)
{
    node *newNode = new node();
    newNode->info = temp;
    newNode->next = (*head);
    (*head) = newNode;
}

void insertAfter(node **head, node *prevNode, int temp)
{
    node *first = *head;
    if (prevNode == NULL)
        insertFirst(&first, temp);
    node *newNode = new node();
    newNode->info = temp;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertLast(node **head, int temp)
{
    node *newNode = new node();
    node *last = *head;
    newNode->info = temp;
    newNode->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

void insertBefore(node **head, node *nextNode, int temp)
{
    node *current = *head;
    while (current->next->info != nextNode->info)
        current = current->next;
    node *newNode = new node();
    newNode->info = temp;
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirst(node **head)
{
    node *temp = *head;
    (*head) = temp->next;
}

void deleteLast(node **head)
{
    node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
}

void deleteAfter(node *prevNode)
{
    prevNode->next = prevNode->next->next;
}

bool searchNode(node **head, int key)
{
    node *current = *head;
    while (current != NULL)
    {
        if (current->info == key)
            return true;
        current = current->next;
    }
    return false;
}

int main()
{
    node *head = NULL;
    createList(&head);
    cout << "Insertion : ";
    insertFirst(&head, 20);
    insertAfter(&head, head->next->next, 45);
    insertBefore(&head, head->next->next, 35);
    insertLast(&head, 60);
    printList(head);
    cout << "Deletion  : ";
    deleteFirst(&head);
    deleteLast(&head);
    deleteAfter(head->next);
    printList(head);
    int key = 45;
    if (searchNode(&head, key))
        cout << key << " is found";
    else
        cout << key << " is not found";
    return 0;
}