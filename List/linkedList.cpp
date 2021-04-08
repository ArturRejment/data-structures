#include <iostream>
#include "linkedList.h"
using namespace std;

LinkedList::LinkedList(int data)
{
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

void LinkedList::print()
{
    cout << data << " ";
}

void LinkedList::push_back(LinkedList **head, int data)
{
    LinkedList *newNode = new LinkedList(data);
    LinkedList *temp = (*head);
    LinkedList *temp2 = nullptr;

    while (temp != nullptr)
    {
        temp2 = temp;
        temp = temp->next;
    }

    if ((*head) == nullptr)
    {
        (*head) = newNode;
    }
    else
    {
        temp2->next = newNode;
        newNode->prev = temp2;
        newNode->next = nullptr;
    }
}

void LinkedList::push_front(LinkedList **head, int data)
{
    LinkedList *newNode = new LinkedList(data);
    newNode->prev = nullptr;
    newNode->next = (*head);
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}

void LinkedList::pop_back(LinkedList **head)
{
    LinkedList *temp = (*head);
    LinkedList *temp2 = NULL;

    if ((*head) == NULL)
    {
        return;
    }

    if ((*head)->next == NULL)
    {
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

LinkedList *LinkedList::findElement(LinkedList **head, int val)
{

    LinkedList *temp = (*head);

    if (*head == nullptr)
        return nullptr;

    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::printList(LinkedList *head)
{
    cout << "Linked list: " << flush;
    while (head != NULL)
    {
        head->print();
        head = head->next;
    }
}
