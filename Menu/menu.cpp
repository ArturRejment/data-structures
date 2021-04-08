#include <iostream>
#include <conio.h>
#include "../List/listLogic.cpp"
#include "../Array/arrayLogic.cpp"
#include "../Heap/heap.cpp"
<<<<<<< HEAD
#include "../RBTree/RBTree.cpp"
#include "../Logic/mainLogic.cpp"
=======
>>>>>>> main
using namespace std;

//* Structures Declaration
LinkedList *head = nullptr;
Array array = Array();
Heap heap = Heap();
RBTree tree = RBTree();

void printDefaultMenu()
{
    cout << "[1] Add element\n";
    cout << "[2] Delete element\n";
    cout << "[3] Find element\n";
    cout << "[4] Print structure\n";
    cout << "[5] Fill structure with random values\n";
    cout << "[6] Fill structure with values from the file\n";
    cout << "[7] Return\n";
}

void arrayMenu()
{
    do
    {
        cout << "------------- ARRAY MENU -------------" << endl;
        printDefaultMenu();
        cout << "[8] Add element on a position\n";
        cout << "[9] Add element at the beginning\n";
        cout << "[a] Delete array\n";

        char choice = getch();
        int val;
        int pos;

        switch (choice)
        {
        case '1':
            cout << "Enter value: ";
            cin >> val;
            array.addElement(val);
            break;
        case '2':
            cout << "Enter value: ";
            cin >> val;
            array.deleteElement(val);
            break;
        case '4':
            array.printArray();
            break;
        case '5':
            fillArrayWithRandomData(&array);
            break;
        case '8':
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            array.addElementOnPosition(val, pos);
            break;
        case '9':
            cout << "Enter value: ";
            cin >> val;
            array.addElementAtTheBegenning(val);
            break;
        case 'a':
            deleteArray(&array);
            break;
        case '7':
            return;
            break;

        default:
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
            cout << "Enter value: ";
            cin >> val;
            LinkedList::push_back(&head, val);
            break;
        case '2':
            LinkedList::pop_back(&head);
            break;
        case '3':
            cout << "Enter value to find: ";
            cin >> val;
            LinkedList *elem;
            elem = LinkedList::findElement(&head, val);
            if (elem != nullptr)
                elem->print();
            else
                cout << "Element " << val << " is not in the List" << endl;
            break;
        case '4':
            LinkedList::printList(head);
            break;
        case '5':
            fillLinkedListWithRandomData(head);
            break;
        case '6':
            fillLinkedListFromFile(head);
            break;
        case '7':
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
            cout << "Enter value: ";
            cin >> val;
            heap.insert(val);
            break;
        case '4':
            heap.printHeap();
            break;
        case '7':
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
            cout << "Enter value: ";
            cin >> val;
            tree.insertElement(val);
            break;
        case '2':
            cout << "Enter value: ";
            cin >> val;
            tree.deleteElement(tree.find(val));
            break;
        case '3':
            cout << "Enter value: ";
            cin >> val;
            RBNode *temp;
            temp = tree.find(val);
            if (temp != nullptr)
                cout << "Found " << val;
            else
                cout << "Element " << val << " is not in the structure\n";
            break;
        case '4':
            tree.inorder();
            break;
        case '7':
            return;

        default:
            break;
        }
    } while (true);
}

void printMenu()
{
    do
    {
        char choice;
        system("clear");

        cout << "------------- MENU -------------" << endl;
        cout << "[1] Array" << endl;
        cout << "[2] Linked list" << endl;
        cout << "[3] Binary heap" << endl;
        cout << "[4] Red-black tree" << endl;
        cout << "[5] Exit program" << endl;

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