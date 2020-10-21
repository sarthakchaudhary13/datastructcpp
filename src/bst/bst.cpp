#include <iostream>

struct Node
{
    int val;
    Node *right = nullptr;
    Node *left = nullptr;
};

class Bst
{
public:
    Node *root = nullptr;
    void createBst(int *arr, int n);
    void addNode(int n);
};

void Bst::addNode(int n)
{
    Node *prev = this->root;
    Node *tmp = this->root;
    while (tmp != nullptr)
    {
        prev = tmp;

        if (tmp->val > n)
            tmp = tmp->left;
        else if (tmp->val < n)
            tmp = tmp->right;
        else
            break;
    }

    if (tmp == nullptr) {
        Node *newnode = new Node;
        newnode->val = n;
        if (prev->val > n) 
            prev->left = newnode;
        else if (prev->val < n)
            prev->right = newnode;
    }
}

void Bst::createBst(int *arr, int n)
{
    this->root = new Node;
    this->root->val = *arr;

    for (int i = 1; i < n; i++)
    {
        this->addNode(arr[i]);
    }
}

int main() {
    Bst a;
    int ar[3] = {1,2,3,4,5,6,7,8,9,10};
    a.createBst(ar,3);
    std::cout << a.root->val << a.root->right->val << a.root->right->right->val;
}