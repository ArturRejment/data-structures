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

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        LinkedList::push_back(&list, value);
    }
}