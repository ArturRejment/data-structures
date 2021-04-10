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

void fillArrayforExperiment(Array *array, int size)
{
    if (!array->isEmpty())
    {
        deleteArray(array);
    }
    for (int i = 0; i < size; i++)
    {
        int value = rand() % 100000;
        array->addElement(value);
    }
}

void arrayExperiment(Array *array)
{
    srand(time(NULL));
    int size, value;
    float time;

    cout << "Please enter the size of the list: " << flush;
    cin >> size;

    //! Insert at the end
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        value = rand() % 100000;
        Timer timer;
        array->addElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element at the end of the array took on average: " << time / 100 << " ms\n";

    //! Insert at the beginning
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        value = rand() % 100000;
        Timer timer;
        array->addElementAtTheBegenning(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element at the beginning of the array took on average: " << time / 100 << " ms\n";

    //! Insert at the position
    time = 0;
    int position;
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        value = rand() % 100000;
        position = rand() % (size - 1);
        Timer timer;
        array->addElementOnPosition(value, position);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element at the random position of the array took on average: " << time / 100 << " ms\n";

    //! Delete from the end
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        Timer timer;
        array->deleteFromTheEnd();
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the end of the array took on average: " << time / 100 << " ms\n";

    //! Delete from the beginning
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        Timer timer;
        array->deleteFromTheBeginning();
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the beginning of the array took on average: " << time / 100 << " ms\n";

    //! Delete from the random position
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        position = rand() % (size - 1);
        Timer timer;
        array->deleteElement(position);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the random position in the array took on average: " << time / 100 << " ms\n";

    //! Find element
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillArrayforExperiment(array, size);
        value = rand() % 100000;
        Timer timer;
        array->findElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Finding element in the array took on average: " << time / 100 << " ms\n";
}
