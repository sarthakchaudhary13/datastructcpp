enum loc
{
    start,
    end,
    custom
};

class Node
{
private:
    int val = 0;
    Node *next = nullptr;
    Node *prev = nullptr;

public:
    int getVal()
    {
        return val;
    }

    Node *nextNode()
    {
        return next;
    }

    Node *prevNode()
    {
        return prev;
    }
    void deleteNode();
friend class LinkedList;
};

class LinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int totalNodes = 0;

public:
    // Constructer and destructors
    ~LinkedList();

    Node *getHead();

    // operations on Nodes
    Node *createNode(int val = 0, int loc = loc::end, int customIdx = -1);
    
    Node* gotoNodeByIdx(int idx);
    Node* gotoNodeByVal(int val);
    void sort();
};