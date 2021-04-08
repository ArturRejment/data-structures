#include <iostream>
#include <conio.h>
#include "../List/listLogic.cpp"
#include "../Array/arrayLogic.cpp"
#include "../Heap/heap.cpp"
#include "../RBTree/RBTree.cpp"
#include "../Logic/mainLogic.cpp"
using namespace std;

//* Structures Declaration
LinkedList list = LinkedList();
Array array = Array();
Heap heap = Heap();
RBTree tree = RBTree();

void printDefaultMenu()
{
    cout << "[1] Add element\n";
    cout << "[2] Delete element\n";
    cout << "[3] Fill structure with random values\n";
    cout << "[4] Fill structure with values from the file\n";
    cout << "[5] Find element\n";
    cout << "[6] Print structure\n";
    cout << "[7] Clear structure\n";
    cout << "[8] Return\n";
    cout << "Press key with your choice\n";
}

int askForValue()
{
    int val;
    cout << "Enter value: ";
    cin >> val;
    return val;
}

void arrayMenu()
{
    do
    {
        cout << "------------- ARRAY MENU -------------" << endl;
        printDefaultMenu();

        char choice = getch();
        int val;
        int pos;

        switch (choice)
        {
        case '1':
            array.addElement(askForValue());
            break;
        case '2':
            array.deleteElement(askForValue());
            break;
        case '3':
            fillArrayWithRandomData(&array);
            break;
        case '6':
            array.printArray();
            break;
        case '7':
            deleteArray(&array);
            break;
        case '8':
            return;
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (true);
}

void listMenu()
{
    do
    {
        cout << "------------- LINKED LIST MENU -------------" << endl;
        printDefaultMenu();

        char choice = getch();
        int val;

        switch (choice)
        {
        case '1':
            list.push_back(askForValue());
            break;
        case '2':
            list.pop_back();
            break;
        case '3':
            fillLinkedListWithRandomData(&list);
            break;
        case '4':
            fillLinkedListFromFile(&list);
            break;
        case '5':
            ListNode *elem;
            elem = list.findElement(askForValue());
            if (elem != nullptr)
                elem->printData();
            else
                cout << "Element " << val << " is not in the List" << endl;
            break;
        case '6':
            list.printList();
            break;
        case '7':
            deleteList(&list);
            break;
        case '8':
            return;
            break;
        default:
            break;
        }
    } while (true);
}

void heapMenu()
{
    do
    {
        cout << "------------- BINARY HEAP MENU -------------" << endl;
        printDefaultMenu();

        char choice = getch();
        int val;

        switch (choice)
        {
        case '1':
            heap.insert(askForValue());
            break;
        case '2':
            heap.deleteElement(askForValue());
            break;
        case '5':
            heap.findElement(askForValue());
        case '6':
            heap.printHeap();
            break;
        case '8':
            return;
            break;

        default:
            break;
        }
    } while (true);
}

void treeMenu()
{
    do
    {
        cout << "------------- RED-BLACK TREE MENU -------------" << endl;
        printDefaultMenu();

        char choice = getch();
        int val;

        switch (choice)
        {
        case '1':
            tree.insertElement(askForValue());
            break;
        case '2':
            tree.deleteElement(tree.find(askForValue()));
            break;
        case '5':
            RBNode *temp;
            temp = tree.find(askForValue());
            if (temp != nullptr)
                cout << "Found " << val;
            else
                cout << "Element " << val << " is not in the structure\n";
            break;
        case '6':
            tree.inorder();
            break;
        case '8':
            return;

        default:
            break;
        }
    } while (true);
}

void printExperimentMenu()
{
    char choice;
    system("clear");

    cout << "------------- EXPERIMENT MENU -------------" << endl;
    cout << "[1] Array" << endl;
    cout << "[2] Linked list" << endl;
    cout << "[3] Binary heap" << endl;
    cout << "[4] Red-black tree" << endl;
    cout << "[5] Exit" << endl;

    choice = getch();
    switch (choice)
    {
    case '1':
        arrayMenu();
        break;
    case '2':
        listMenu();
        break;
    case '3':
        heapMenu();
        break;
    case '4':
        treeMenu();
        break;
    case '5':
        return;
        break;
    default:
        return;
        break;
    }
}

void printTestingMenu()
{
    do
    {
        char choice;
        system("clear");

        cout << "------------- TESTING MENU -------------" << endl;
        cout << "[1] Array" << endl;
        cout << "[2] Linked list" << endl;
        cout << "[3] Binary heap" << endl;
        cout << "[4] Red-black tree" << endl;
        cout << "[5] Exit" << endl;

        choice = getch();
        switch (choice)
        {
        case '1':
            arrayMenu();
            break;
        case '2':
            listMenu();
            break;
        case '3':
            heapMenu();
            break;
        case '4':
            treeMenu();
            break;
        case '5':
            return;
            break;
        default:
            return;
            break;
        }
    } while (true);
}

void selectMode()
{
    cout << "-------------- START ----------------\n";
    cout << "[1] Experiment mode\n";
    cout << "[2] Testing mode\n";
    cout << "[3] Exit program\n";
    cout << "Press key with your choice\n";

    char choice = getch();
    switch (choice)
    {
    case '1':
        printExperimentMenu();
        break;
    case '2':
        printTestingMenu();
        break;

    default:
        break;
    }
}