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

void fillHeapForExperiment(Heap *heap, int size)
{
    if (!heap->isEmpty())
    {
        deleteHeap(heap);
    }
    for (int i = 0; i < size; i++)
    {
        int value = rand() % 30000;
        heap->insert(value);
    }
}

void heapExperiment(Heap *heap)
{
    srand(time(NULL));
    int size, value;
    float time;

    cout << " Please enter the size of the heap: " << flush;
    cin >> size;

    //! Insert element
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillHeapForExperiment(heap, size);
        value = rand() % 30000;
        Timer timer;
        heap->insert(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element to the heap took on average: " << time / 100 << " ms\n";

    //! Delete element
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillHeapForExperiment(heap, size);
        value = rand() % 30000;
        Timer timer;
        heap->deleteElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the heap took on average: " << time / 100 << " ms\n";

    //! Find element
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillHeapForExperiment(heap, size);
        value = rand() % 30000;
        Timer timer;
        heap->findElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Finding element in the heap took on average: " << time / 100 << " ms\n";
}