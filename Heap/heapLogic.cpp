#include <fstream>
#include <time.h>
#include "heap.cpp"

void deleteHeap(Heap *heap)
{
    Heap newHeap = Heap();
    *heap = newHeap;
}

void fillHeapFromFile(Heap *heap)
{
    fstream file;
    file.open("data.txt", ios::in);

    if (!file.is_open())
    {
        cout << "[Heap] Cannot open data.txt\n";
        return;
    }

    int size;
    int data;
    file >> size;

    while ((!file.eof()))
    {
        file >> data;
        heap->insert(data);
    }
}

void fillHeapWithRandomData(Heap *heap)
{
    srand(time(NULL));

    if (!heap->isEmpty())
    {
        cout << "Heap is not empty!\n";
        return;
    }

    int size;
    cout << "Enter the size of the heap: " << flush;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        heap->insert(value);
    }
}