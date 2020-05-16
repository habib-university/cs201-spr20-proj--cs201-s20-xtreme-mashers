#include <iostream>

template <class T>
class ReferenceTree;

template <class T>
class Node
{
    private:
    T _val;
    Node* _left;
    Node* _right;

    public:
    Node(T& val, Node* left, Node* right)
    {
        _val = val;
        _left = left;
        _right = right;
    }
    ~Node();
    Node* getRight() {return _right;}
    Node* getLeft() {return _left;}
    void setRight(Node* right) {_right = right;}
    void setLeft(Node* left) {_left = left;}
    T getVal() {return _val;}
};

template <class T>
class ReferenceTree
{
    private:
    Node<T>* _root;

    public:
    ReferenceTree();
    ~ReferenceTree();

    void insert(Node<T>*);
    bool search(Node<T>*);
};