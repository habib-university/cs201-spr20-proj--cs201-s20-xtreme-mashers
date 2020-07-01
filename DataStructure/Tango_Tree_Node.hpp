#pragma once
#include "Red_Black_Tree.hpp"
#include <iostream>
#include <stack>
using namespace std;

class Tango_Tree_Node
{
private:
    int data;
    int color;
    int depth;
    Tango_Tree_Node *parent;
    Tango_Tree_Node *left;
    Tango_Tree_Node *right;
    bool prefered;
    bool isRoot;

public:
    Tango_Tree_Node();
    ~Tango_Tree_Node();
    void set_data(int data_) { data = data_; }
    void set_parent(Tango_Tree_Node *parent_) { parent = parent_; }
    void set_left(Tango_Tree_Node *left_) { left = left_; }
    void set_right(Tango_Tree_Node *right_) { right = right_; }
    void set_color(int color_) { color = color_; }
    void set_depth(int depth_) { depth = depth_; }
    void set_prefered(bool prefered_) { prefered = prefered_; }
    void set_isRoot(bool isRoot_) { isRoot = isRoot_; }

    int get_data() { return data; }
    Tango_Tree_Node *get_parent() { return parent; }
    Tango_Tree_Node *get_left() { return left; }
    Tango_Tree_Node *get_right() { return right; }
    int get_color() { return color; }
    int get_depth() { return depth; }
    bool get_prefered() { return prefered; }
    bool get_isRoot() { return isRoot; }

    void copy_traits(Red_Black_Node *node)
    {
        data = node->get_data();
        depth = node->get_depth();
        prefered = node->get_prefered();
    }
};