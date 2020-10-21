#include <iostream>
#include <string>
#include "linkedlist.hpp"

using namespace std;

/**
 * Node class methods
 * ------------------
*/

/**
 * deleteNode- It does what it says
 * params: None
 * 
 * return: None
 */
 
void Node::deleteNode()
{
    this->next->prev = this->prev;
    this->prev->next = this->next;
    delete this;

}

/**
 * LinkedList class methods implementations start
 * ----------------------------------------------
*/

/**
 * Distructor for linked list;
 * will free all the memory occupied by the list.
*/
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

// returns pointer to the head of the list
Node *LinkedList::getHead()
{
    return head;
}

/**
 * method to insert Node in the list;
 * By default it will add node at the end
 * 
 * params:
 *  val -> value to be inserted default `0`
 *  loc -> where to insert `1 = begining`; `2 = end`; `3 = custom position`
 *  customIdx -> If `loc == 3`; then index where to insert the node.
 * 
 * return: returns pointer to node if created else `nullptr`
*/
Node *LinkedList::createNode(int val, int loc, int customIdx)
{
    //TODO refactor it into smaller functions
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

/**
 * Goto node by index starting from HEAD
 * 
 * params: Index of Node
 * 
 * return: Pointer to Node
*/
Node *LinkedList::gotoNodeByIdx(int idx)
{
    assert(idx < totalNodes && idx >= 0);
    Node *n = head;
    while (idx != 0)
    {
        n = head->next;
        idx--;
    }
    return n;
}

/**
 * linear search
 * 
 * params: value to be searched
 * 
 * return: Pointer to Node
*/
Node *LinkedList::gotoNodeByVal(int val)
{
    Node *n = head;
    while(n != nullptr && n->val != val)
    {
        n = n->next;
    }
    if(n == nullptr)
        return nullptr;
    else
        return n;
}

void LinkedList::sort()
{
    
}
/**
 * End of LinkedList class Methods
 * -------------------------------
*/
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
        Node* a = tmp;
        tmp = tmp->nextNode();
        a->deleteNode();
    }
    return 0;
}