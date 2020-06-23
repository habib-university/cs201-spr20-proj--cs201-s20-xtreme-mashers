#pragma once
#include "Red_Black_Node.hpp"

class Red_Black_Tree
{
    private:
    Red_Black_Node* root;
    Red_Black_Node* TNULL;

    public:
    Red_Black_Tree();
    ~Red_Black_Tree();
    Red_Black_Node* getroot();
    void setroot(Red_Black_Node*);

    void preorder(Red_Black_Node*);
    void inorder(Red_Black_Node*);
    void postorder(Red_Black_Node*);

    Red_Black_Node* searchTree_helper(Red_Black_Node*, int val);
    Red_Black_Node* searchTree(int val);

    Red_Black_Node* minimum(Red_Black_Node*);
    Red_Black_Node* maximum(Red_Black_Node*);
    Red_Black_Node* successor(Red_Black_Node*);
    Red_Black_Node* predecessor(Red_Black_Node*);

    void LeftRotate(Red_Black_Node*);
    void RightRotate(Red_Black_Node*);

    void delete_fix(Red_Black_Node*); //balance tree after deletion
    void rbTransplant(Red_Black_Node*, Red_Black_Node*);
    void deleteNode_helper(Red_Black_Node*, int key);
    void deleteNode(int key);

    void insert_fix(Red_Black_Node*);
    void insert(int key);

    void print_helper(Red_Black_Node*, std::string indent, bool last);
    void print_tree();
};