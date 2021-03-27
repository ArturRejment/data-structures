#include <iostream>
#include "mainLogic.cpp"
using namespace std;

int main()
{
    LinkedList *list = nullptr;
    fillLinkedList(list);
    list->printList(list);

    return 0;
}