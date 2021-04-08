#include <iostream>
using namespace std;

class LinkedList
{
private:
    int data;
    LinkedList *prev;
    LinkedList *next;

public:
    LinkedList();
    void print();
    static void push_back(LinkedList **, int);
    void push_front(LinkedList **, int);
    static void pop_back(LinkedList **);
    static LinkedList *findElement(LinkedList **, int);
    static void printList(LinkedList *);
};