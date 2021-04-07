class Array
{
private:
    int *array;
    int size;

public:
    Array();
    ~Array();
    void addElement(int value);
    void addElementOnPosition(int value);
    void addElementAtTheBegenning(int value);
    void deleteElement(int value);
    void findElement();
    void printArray();
    int getSize();
};