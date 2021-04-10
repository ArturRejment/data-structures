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

bool Array::isEmpty()
{
    if (size <= 0)
        return true;
    return false;
}

void Array::findElement(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return;
        }
    }
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

void Array::deleteFromTheEnd()
{
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}

void Array::deleteFromTheBeginning()
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}

void Array::deleteElement(int position)
{
    for (int i = position; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}