#include <iostream>
#include <stdlib.h>
#include "array.h"

using namespace std;

Array::Array()
{
    this->array = new int[0];
    this->size = 0;
}

Array::~Array()
{
    return;
}

void Array::findElement(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            cout << "Found " << value << " in the array\n";
            return;
        }
    }
    cout << value << " is not in the array\n";
}

int Array::getSize()
{
    return this->size;
}

void Array::addElement(int value)
{
    size++;
    array = (int *)realloc(array, size * sizeof(int));
    array[size - 1] = value;
}

void Array::addElementOnPosition(int value, int position)
{
    position++;

    if (position > size || position < 0)
    {
        return;
    }

    size++;
    array = (int *)realloc(array, size * sizeof(int));
    int i;
    for (i = size; i >= position; i--)
    {
        array[i] = array[i - 1];
    }
    array[i] = value;
}

void Array::addElementAtTheBegenning(int value)
{
    size++;
    array = (int *)realloc(array, size * sizeof(int));
    int i;
    for (i = size; i >= 1; i--)
    {
        array[i] = array[i - 1];
    }
    array[i] = value;
}

void Array::printArray()
{
    cout << "Array: ";
    if (size == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void Array::deleteElement(int value)
{
    int position = -1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            position = i;
    }

    if (position == -1)
        return;

    for (int i = position; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}