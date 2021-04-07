#include <iostream>
<<<<<<< HEAD
=======
#include <math.h>
#include "../Timer/timer.cpp"
>>>>>>> array
#include "array.cpp"

void deleteArray(Array *array)
{
    Array newArray = Array();
    *array = newArray;
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

    float time = 0;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        Timer timer;
        array->addElement(value);
        time += timer.getTime().count() * 1000.0f;
    }

    float avgTime = time / size;

    cout << "Average time for adding element at the end of an array: " << avgTime << " ms\n";

    deleteArray(array);

    time = 0;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        Timer timer;
        array->addElementAtTheBegenning(value);
        time += timer.getTime().count() * 1000.0f;
    }

    avgTime = time / size;

    cout << "Average time for adding element at the beginning of an array: " << avgTime << " ms\n";

    deleteArray(array);

    time = 0;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        Timer timer;
        array->addElementOnPosition(value, (int)floor(array->getSize() / 2));
        time += timer.getTime().count() * 1000.0f;
    }

    avgTime = time / size;

    cout << "Average time for adding element at the particular position of an array: " << avgTime << " ms\n";
}