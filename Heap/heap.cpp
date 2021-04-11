#include <iostream>
#include "heap.h"
using namespace std;

Heap::Heap()
{
    this->size = 0;
    this->heap = nullptr;
    cr = cl = cp = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
}

void Heap::printHeap()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << "\n";
    }
}

bool Heap::isEmpty()
{
    if (size <= 0)
        return true;
    return false;
}

void Heap::findElement(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (heap[i] == value)
        {
            return;
        }
    }
}

void Heap::insert(int value)
{
    if (heap == nullptr)
    {

        heap = new int[1];
        heap[0] = value;
        size++;

        return;
    }
    size++;
    heap = (int *)realloc(heap, size * sizeof(int));
    heap[size - 1] = value;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

void Heap::deleteElement(int value)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (value == heap[i])
            break;
    }

    swap(heap[i], heap[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }

    heap = (int *)realloc(heap, size * sizeof(int));
}

void Heap::heapify(int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
}
