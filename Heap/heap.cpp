#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

void Heap::printHeap()
{
    for (auto val : heap)
    {
        cout << val << " ";
    }
    cout << "\n";
}

void Heap::insert(int value)
{
    if (size + 1 >= heap.size())
    {
        heap.push_back(0);
    }
    heap[++size] = value;
    shiftUp(size);
}

void Heap::shiftUp(int i)
{
    if (i > size)
        return;
    if (i == 1)
        return;
    if (heap[i] > heap[parent(i)])
    {
        swap(heap[parent(i)], heap[i]);
    }
    shiftUp(parent(i));
}

void Heap::shiftDown(int i)
{
    if (i > size)
        return;

    int swapId = i;

    if (leftChild(i) <= size && heap[i] < heap[leftChild(i)])
    {
        swapId = i;
    }

    if (rightChild(i) <= size && heap[swapId < heap[rightChild(i)]])
    {
        swapId = rightChild(i);
    }

    if (swapId != i)
    {
        swap(heap[i], heap[swapId]);
        shiftDown(swapId);
    }
    return;
}