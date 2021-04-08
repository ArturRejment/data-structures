#include <iostream>
#include <math.h>
#include "../Timer/timer.cpp"
#include "array.cpp"

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

    cout << "Average time: " << avgTime << "\n";
}