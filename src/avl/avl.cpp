#include <iostream>

using namespace std;

struct Node
{
    int val;
    int height = 1;
    Node *right = nullptr;
    Node *left = nullptr;
};

class AvlTree
{
public:
    Node *root = nullptr;
    void insert(int val);
    Node *insert(int val, Node *node);
    int balanceFactor(Node *node);
    int nodeHeight(Node *node);
    Node *LLRotation(Node *node);
    Node *LRRotation(Node *node);
    Node *RRRotation(Node *node);
    Node *RLRotation(Node *node);
};

int AvlTree::balanceFactor(Node *node)
{
    int hl, hr;
    hl = node && node->left ? node->left->height : 0;
    hr = node && node->right ? node->right->height : 0;

    return hl - hr;
}

int AvlTree::nodeHeight(Node *node)
{
    int hl, hr;
    hl = node && node->left ? node->left->height : 0;
    hr = node && node->right ? node->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

Node *AvlTree::LLRotation(Node *node)
{
    Node *node_left, *node_right;
    node_left = node->left;
    node_right = node_left->right;
    node_left->right = node;
    node->left = node_right;

    node->height = nodeHeight(node);
    node_left->height = nodeHeight(node_left);
    if (node == this->root)
        this->root = node_left;
    
    return node_left;
}
    Node *AvlTree::LRRotation(Node *node){
        Node *LNode = node->left;
        Node *LRNode = LNode->right;
        Node *LRNodeRchild = LRNode->right;
        Node *LRNodeLChild = LRNode->left;

        LNode->right = LRNodeLChild;
        node->left = LRNodeRchild;
        LRNode->left = LNode;
        LRNode->right = node;

        LNode->height = nodeHeight(LNode);
        node->height = nodeHeight(node);
        LRNode->height = nodeHeight(LRNode);

        if (node == this->root)
            this->root = LRNode;
        
        return LRNode;
    }
    Node *AvlTree::RRRotation(Node *node){
        return nullptr;
    }
    Node *AvlTree::RLRotation(Node *node){
        return nullptr;
    }
Node *AvlTree::insert(int val, Node *node)
{
    if (node == nullptr)
    {
        Node *innode = new Node;
        innode->val = val;
        return innode;
    }
    else
    {
        if (val > node->val)
            node->right = insert(val, node->right);
        else if (val < node->val)
            node->left = insert(val, node->left);
        else
            return node;
    }

    node->height = nodeHeight(node);

    if (balanceFactor(node) == 2 && balanceFactor(node->left) == 1)
        return LLRotation(node);
    else if (balanceFactor(node) == 2 && balanceFactor(node->left) == -1)
        return LRRotation(node);
    else if (balanceFactor(node) == -2 && balanceFactor(node->right) == -1)
        return RRRotation(node);
    else if (balanceFactor(node) == -2 && balanceFactor(node->right) == 1)
        return RLRotation(node);
    return node;

}

void AvlTree::insert(int val)
{
    if (this->root == nullptr)
    {
        Node *innode = new Node;
        innode->val = val;
        this->root = innode;
    }
    else
        insert(val, this->root);
}

int main()
{
    AvlTree a;
    a.insert(20);
    a.insert(10);
    a.insert(15);
    a.insert(16);
    return 1;
    // cout << a.root->val << a.root->left->val << a.root->right->val;
}