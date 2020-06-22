#include "Red_Black_Node.hpp"

Red_Black_Node::Red_Black_Node(int _value, Red_Black_Node* _parent, int _colour)
{
    value = _value;
    parent = _parent;
    colour = _colour;
    left = nullptr;
    right = nullptr;
}

Red_Black_Node::Red_Black_Node(int _value, Red_Black_Node* _parent)
{
    value = _value;
    parent = _parent;
    colour = 0;
    left = nullptr;
    right = nullptr;
}

Red_Black_Node::Red_Black_Node(int _colour)
{
    colour = _colour;
    left = nullptr;
    right = nullptr;
}

Red_Black_Node::Red_Black_Node()
{

}

Red_Black_Node::~Red_Black_Node()
{

}

void Red_Black_Node::set_value(int _value)
{
    value = _value;
}

void Red_Black_Node::set_colour(int _colour)
{
    colour = _colour;
}

void Red_Black_Node::set_Right(Red_Black_Node* _right)
{
    right = _right;
}

void Red_Black_Node::set_Left(Red_Black_Node* _left)
{
    left = _left;
}

void Red_Black_Node::set_Right(Red_Black_Node* _parent)
{
    parent = _parent;
}

int Red_Black_Node::get_value()
{
    return value;
}

int Red_Black_Node::get_colour()
{
    return colour;
}

Red_Black_Node* Red_Black_Node::get_Left()
{
    return left;
}

Red_Black_Node* Red_Black_Node::get_Right()
{
    return right;
}

Red_Black_Node* Red_Black_Node::get_Parent()
{
    return parent;
}