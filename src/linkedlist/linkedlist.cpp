#include <iostream>
#include <string>
#include "linkedlist.hpp"

using namespace std;

LinkedList::~LinkedList()
{
    Node *cn = head;
    while (cn != nullptr)
    {
        Node *tmp = cn;
        cn = cn->next;
        delete tmp;
    }
}

Node *LinkedList::getHead()
{
    return head;
}

Node *LinkedList::createNode(int val, int loc, int customIdx)
{
    Node *n = nullptr;
    if (this->head == nullptr)
    {
        n = new Node;
        n->val = val;
        this->head = n;
        this->tail = n;
    }
    else if (loc == loc::start)
    {
        n = new Node;
        n->val = val;
        n->next = this->head;
        n->prev = this->tail;
        this->head->prev = n;
        this->tail->next = n;
        this->head = n;
    }
    else if (loc == loc::end || customIdx == this->totalNodes)
    {
        n = new Node;
        n->val = val;
        n->prev = this->tail;
        this->tail->next = n;
        this->tail = n;
    }
    else if (customIdx < this->totalNodes)
    {
        Node *tmp = this->head;
        while (customIdx > 0)
        {
            tmp = tmp->next;
            customIdx--;
        }
        n = new Node;
        n->val = val;
        n->next = tmp->next;
        n->prev = tmp;
        n->next->prev = n;
        tmp->next = n;
    }

    return n;
}

void LinkedList::deleteNode(Node *node)
{
    if (node == nullptr)
    {
        while(head != tail)
        {
            Node *tmp = head;
            delete tmp;
            head = head->next;
        }
        delete head;
        head = nullptr;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
}

int main()
{

    LinkedList l = LinkedList();
    l.createNode(2);
    l.createNode(3);
    l.createNode(4);
    l.createNode(5);
    Node *tmp = l.getHead();
    while (tmp != nullptr)
    {
        cout << tmp->getVal() << endl;
        tmp = tmp->nextNode();
    }
    l.deleteNode();
    return 0;
}