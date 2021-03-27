#include <iostream>
using namespace std;

class LinkedList
{

private:
    int data;
    LinkedList *prev;
    LinkedList *next;

public:
    LinkedList(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    void print()
    {
        cout << this->prev << " " << data << " " << this->next << endl;
    }

    void push_back(LinkedList **head, int data)
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

    void push_front(LinkedList **head, int data)
    {
        LinkedList *newNode = new LinkedList(data);
        newNode->prev = nullptr;
        newNode->next = (*head);
        if ((*head) != nullptr)
            (*head)->prev = newNode;
        (*head) = newNode;
    }

    void printList(LinkedList *head)
    {
        while (head != NULL)
        {
            head->print();
            head = head->next;
        }
    }
};