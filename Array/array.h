class Array
{
private:
    int *array;
    int size;

public:
    Array();
    ~Array();
    void addElement(int value);
    void deleteElement();
    void findElement();
    void printArray();
};