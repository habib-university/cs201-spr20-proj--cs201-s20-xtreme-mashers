#pragma once
#include "Tango_subtree.hpp"
#include <iostream>
#include <stack>
using namespace std;

class TangoTree
{
private:
    Tango_Tree_Node *root;

public:
    TangoTree(){};
    ~TangoTree(){};
    void Construction(Red_Black_Tree* ref_tree)
    {
        ref_tree->setDepth();

    }
};