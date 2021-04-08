#include <iostream>
#include <math.h>
#include "array.cpp"

void deleteArray(Array *array)
{
    Array newArray = Array();
    *array = newArray;
}

void fillArrayFromFile(Array *array)
{
    fstream file;
    file.open("data.txt", ios::in);

    if (!file.is_open())
    {
        cout << "[Array] Cannot open data.txt\n";
        return;
    }

    int size;
    int data;
    file >> size;

    while ((!file.eof()))
    {
        file >> data;
        array->addElement(data);
    }
}

void fillArrayWithRandomData(Array *array)
{
    if (array->getSize() > 0)
    {
        cout << "Array is not empty!";
        return;
    }

    int size;
    cout << "Enter the size of the array: " << flush;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        array->addElement(value);
    }
}