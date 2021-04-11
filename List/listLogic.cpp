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
        list->push_back(value);
    }
}

void fillListForExperiment(LinkedList *list, int size)
{
    srand(time(NULL));

    if (!list->isEmpty())
    {
        deleteList(list);
    }
    for (int i = 0; i < size; i++)
    {
        int value = rand() % 30000;
        list->push_back(value);
    }
}

void linkedListExperiment(LinkedList *list)
{
    srand(time(NULL));
    int size, value;
    float time;

    cout << "Please enter the size of the list: " << flush;
    cin >> size;

    //! Insert at the end
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillListForExperiment(list, size);
        value = rand() % 30000;
        Timer timer;
        list->push_back(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element at the end of the double linked list took on average: " << time / 100 << " ms\n";

    //! Insert at the beginning
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillListForExperiment(list, size);
        value = rand() % 30000;
        Timer timer;
        list->push_front(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element at the beginning of the double linked list took on average: " << time / 100 << " ms\n";

    //! Insert at random position
    time = 0;
    int position;
    for (int i = 0; i < 100; i++)
    {
        fillListForExperiment(list, size);
        value = rand() % 100000;
        position = rand() % (size - 1);
        Timer timer;
        list->insert(value, position);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element at the random position of the double linked list took on average: " << time / 100 << " ms\n";

    //! Deletion element form the end
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillListForExperiment(list, size);
        Timer timer;
        list->pop_back();
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the end of the double linked list took on average: " << time / 100 << " ms\n";

    //! Deletion element form the beginning
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillListForExperiment(list, size);
        Timer timer;
        list->pop_front();
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the beginning of the double linked list took on average: " << time / 100 << " ms\n";

    //! Finding element in the list
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillListForExperiment(list, size);
        value = rand() % 30000;
        Timer timer;
        list->findElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Finding element in the double linked list took on average: " << time / 100 << " ms\n";
}
