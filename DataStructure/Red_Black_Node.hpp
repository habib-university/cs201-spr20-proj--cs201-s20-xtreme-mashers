#pragma once
#include <iostream>

class Red_Black_Node
{
    private:
    int value;
    int colour; //0-black, 1-red
    int depth;
    Red_Black_Node* right;
    Red_Black_Node* left;
    Red_Black_Node* parent;
    bool preffered_child;

    public:
    Red_Black_Node(int _value, Red_Black_Node* _parent, int _colour);
    Red_Black_Node(int _value, Red_Black_Node* _parent);
    Red_Black_Node(int _colour);
    Red_Black_Node();
    ~Red_Black_Node();

    void set_depth(int);
    void set_value(int);
    void set_colour(int);
    void set_Right(Red_Black_Node*);
    void set_Left(Red_Black_Node*);
    void set_Parent(Red_Black_Node*);
    void set_preffered(bool);

    int get_value();
    int get_colour();
    int get_depth();
    Red_Black_Node* get_Right();
    Red_Black_Node* get_Left();
    Red_Black_Node* get_Parent();
    bool get_preffered();
};