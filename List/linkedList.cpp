#include <iostream>
#include "../Timer/timer.cpp"
#include "linkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

bool LinkedList::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

void LinkedList::printList()
{
    ListNode *temp = head;
    if (temp == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::push_back(int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LinkedList::push_front(int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::pop_back()
{
    if (tail == nullptr)
    {
        cout << "List is already empty!\n";
        return;
    }

    ListNode *temp = tail;
    tail->prev->next = nullptr;
    tail = tail->prev;
    free(temp);
}

void LinkedList::pop_front()
{

    if (head == nullptr)
    {
        cout << "List is already empty!\n";
        return;
    }

    ListNode *temp = head;
    head = head->next;
    head->prev = nullptr;
    free(temp);
}

ListNode *LinkedList::findElement(int val)
{

    ListNode *temp = head;

    if (head == nullptr)
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
