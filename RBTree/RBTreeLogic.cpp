#include <fstream>
#include <time.h>
#include "RBTree.cpp"

void deleteTree(RBTree *tree)
{
    RBTree newTree = RBTree();
    *tree = newTree;
}

void fillTreeFromFile(RBTree *tree)
{
    fstream file;
    file.open("data.txt", ios::in);

    if (!file.is_open())
    {
        cout << "[Red-Black Tree] Cannot open data.txt\n";
        return;
    }

    int size;
    int data;
    file >> size;

    while ((!file.eof()))
    {
        file >> data;
        tree->insertElement(data);
    }
}

void fillTreeWithRandomData(RBTree *tree)
{
    srand(time(NULL));

    if (!tree->isEmpty())
    {
        cout << "Red-Black Tree is not empty!\n";
        return;
    }

    int size;
    cout << "Enter the size of the tree: " << flush;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        tree->insertElement(value);
    }
}

void fillTreeForExperiment(RBTree *tree, int size, int range)
{
    int value;
    if (!tree->isEmpty())
    {
        deleteTree(tree);
    }

    for (int i = 0; i < size; i++)
    {
        value = rand() % range;
        tree->insertElement(value);
    }
}

void treeExperiment(RBTree *tree)
{
    srand(time(NULL));
    int size, value, testNumber, range;
    float time;

    cout << "\nPlease enter the size of the red-black tree: " << flush;
    cin >> size;

    cout << "Please enter number of tests: " << flush;
    cin >> testNumber;

    cout << "Please enter maximum size of the arguments in structure: " << flush;
    cin >> range;

    //! Insert element
    time = 0;
    for (int i = 0; i < testNumber; i++)
    {
        fillTreeForExperiment(tree, size, range);
        value = rand() % range;
        Timer timer;
        tree->insertElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element to the red-black tree took on average: " << time / testNumber << " ms\n";

    //! Delete element
    time = 0;
    RBNode *node;
    for (int i = 0; i < testNumber; i++)
    {
        fillTreeForExperiment(tree, size, range);
        value = rand() % range;
        Timer timer;
        node = tree->find(value);
        if (node == nullptr)
            continue;
        tree->deleteElement(node);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element form the red-black tree took on average: " << time / testNumber << " ms\n";

    //! Find element
    time = 0;
    for (int i = 0; i < testNumber; i++)
    {
        fillTreeForExperiment(tree, size, range);
        value = rand() % range;
        Timer timer;
        tree->find(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Finding element in the red-black tree took on average: " << time / testNumber << " ms\n";
}