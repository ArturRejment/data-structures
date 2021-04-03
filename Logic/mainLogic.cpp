#include <fstream>
#include <iostream>
#include "./List/linkedList.cpp"

using namespace std;

void fillLinkedList(LinkedList *&list)
{
    fstream file;
    file.open("data.txt", ios::in);
    if (!file.is_open())
    {
        cout << "[LinkedList] Cannot open data.txt" << endl;
        return;
    }

    int size;
    int data;
    file >> size;

    while (!file.eof())
    {
        file >> data;
        list->push_back(&list, data);
    }
}