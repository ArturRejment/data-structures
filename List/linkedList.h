#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void printData()
    {
        cout << data << "\n";
    }
};

class LinkedList
{
private:
    ListNode *head;
    ListNode *tail;

public:
    LinkedList();
    void printList();
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    void insert(int, int);
    ListNode *findElement(int);
    static void printList(ListNode *);
    bool isEmpty();
};