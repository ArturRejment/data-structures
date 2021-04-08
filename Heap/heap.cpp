#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

Heap::Heap()
{
    this->size = 0;
    this->heap = nullptr;
}

void Heap::printHeap()
{
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << "\n";
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

// void Heap::shiftUp(int i)
// {
//     if (i > size)
//         return;
//     if (i == 1)
//         return;
//     if (heap[i] > heap[parent(i)])
//     {
//         swap(heap[parent(i)], heap[i]);
//     }
//     shiftUp(parent(i));
// }

// void Heap::shiftDown(int i)
// {
//     if (i > size)
//         return;

//     int swapId = i;

//     if (leftChild(i) <= size && heap[i] < heap[leftChild(i)])
//     {
//         swapId = leftChild(i);
//     }

//     if (rightChild(i) <= size && heap[swapId] < heap[rightChild(i)])
//     {
//         swapId = rightChild(i);
//     }

//     if (swapId != i)
//     {
//         swap(heap[i], heap[swapId]);
//         shiftDown(swapId);
//     }
//     return;
// }