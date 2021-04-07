#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void fillLinkedListFromFile(LinkedList *&list)
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

void fillLinkedListWithRandomData(LinkedList *&list)
{
    srand(time(NULL));

    if (list != nullptr)
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
        LinkedList::push_back(&list, value);
        time += timer.getTime().count() * 1000.0f;
    }

    float avgTime = time / size;

    cout << "Average time: " << avgTime << "\n";
}