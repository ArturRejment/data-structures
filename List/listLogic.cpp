#include <iostream>
#include <time.h>
#include <fstream>
#include "linkedList.cpp"

void deleteList(LinkedList *list)
{
    LinkedList newList = LinkedList();
    *list = newList;
}

void fillLinkedListFromFile(LinkedList *list)
{
    fstream file;
    file.open("data.txt", ios::in);
    if (!file.is_open())
    {
        cout << "[LinkedList] Cannot open data.txt\n";
        return;
    }

    int size;
    int data;
    file >> size;

    while (!file.eof())
    {
        file >> data;
        list->push_back(data);
    }
}

void fillLinkedListWithRandomData(LinkedList *list)
{
    srand(time(NULL));

    if (!list->isEmpty())
    {
        cout << "List is not empty!";
        return;
    }

    int size;
    cout << "Enter the size of the list: " << flush;
    cin >> size;

    float time = 0;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        Timer timer;
        list->push_back(value);
        time += timer.getTime().count() * 1000.0f;
    }

    float avgTime = time / size;

    cout << "Average time of push_back: " << avgTime << " ms\n";

    deleteList(list);

    time = 0;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        Timer timer;
        list->push_front(value);
        time += timer.getTime().count() * 1000.0f;
    }

    avgTime = time / size;

    cout << "Average time of push_front: " << avgTime << " ms\n";
}
