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
    string cr, cl, cp;

public:
    RBTree();
    ~RBTree();
    void print();
    void printTree(string, string, RBNode *);
    void inorder();
    RBNode *find(int k);
    RBNode *findMin(RBNode *node);
    RBNode *findSuccessor(RBNode *node);
    RBNode *getRoot();
    void leftRotation(RBNode *node);
    void rightRotation(RBNode *node);
    void insertElement(int value);
    RBNode *insertElementNormalBST(RBNode *root, RBNode *node);
    void restoreRBTreeProperties(RBNode *node);
    void deleteElement(RBNode *nodeToDelete);
    void deleteTree(RBNode *node);
};