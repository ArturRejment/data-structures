enum Color
{
    RED,
    BLACK
};

struct RBNode
{
    int data;
    bool color;
    RBNode *leftChild;
    RBNode *rightChild;
    RBNode *parent;

    RBNode(int data)
    {
        this->data = data;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->parent = nullptr;
        this->color = RED;
    }
};

class RBTree
{
private:
    RBNode *root;

public:
    RBTree();
    ~RBTree();
    void printTree();
    RBNode *find(int k);
    RBNode *findMin(RBNode *node);
    RBNode *findSuccessor(RBNode *node);
    void leftRotation(RBNode *node);
    void rightRotation(RBNode *node);
    void insertElement(int value);
    void deleteElement(RBNode *nodeToDelete);
};