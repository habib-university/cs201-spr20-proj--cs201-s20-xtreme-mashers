// #include "Red_Black_Tree.hpp"

// Red_Black_Tree::Red_Black_Tree()
// {
//     TNULL = new Red_Black_Node(0);
//     root = NULL;
// }

// Red_Black_Tree::~Red_Black_Tree()
// {

// }

// Red_Black_Node* Red_Black_Tree::getroot()
// {
//     return this->root;
// }

// void Red_Black_Tree::setroot(Red_Black_Node* _root)
// {
//     this->root = _root;
// }

// void Red_Black_Tree::preorder(Red_Black_Node* node)
// {
//     if (node != TNULL)
//     {
//         std::cout << node->get_value() << " ";
//         preorder(node->get_Left());
//         preorder(node->get_Right());
//     }
// }

// void Red_Black_Tree::inorder(Red_Black_Node* node)
// {
//     if (node != TNULL)
//     {
//         preorder(node->get_Left());
//         std::cout << node->get_value() << " ";
//         preorder(node->get_Right());
//     }
// }

// void Red_Black_Tree::postorder(Red_Black_Node* node)
// {
//     if (node != TNULL)
//     {
//         preorder(node->get_Left());
//         preorder(node->get_Right());
//         std::cout << node->get_value() << " ";
//     }
// }

// Red_Black_Node* Red_Black_Tree::searchTree_helper(Red_Black_Node* node, int val)
// {
//     if (node == TNULL || val == node->get_value())
//     {
//         return node;
//     }

//     if (val < node->get_value())
//     {
//         node->get_Left()->set_preffered(true);
//         node->get_Right()->set_preffered(false);
//         return searchTree_helper(node->get_Left(), val);
//     }

//     node->get_Left()->set_preffered(false);
//     node->get_Right()->set_preffered(true);
//     return searchTree_helper(node->get_Right(), val);
// }

// Red_Black_Node* Red_Black_Tree::searchTree(int val)
// {
//     return searchTree_helper(this->root, val);
// }

// Red_Black_Node* Red_Black_Tree::minimum(Red_Black_Node* node)
// {
//     while(node->get_Left() != nullptr)
//     {
//         node = node->get_Left();
//     }
//     return node;
// }

// Red_Black_Node* Red_Black_Tree::maximum(Red_Black_Node* node)
// {
//     while(node->get_Left() != nullptr)
//     {
//         node = node->get_Right();
//     }
//     return node;
// }

// Red_Black_Node* Red_Black_Tree::successor(Red_Black_Node* node)
// {
//     if (node->get_Right() != nullptr)
//     {
//         return minimum(node->get_Right());
//     }

//     Red_Black_Node* node2 = node->get_Parent();
//     while (node2 != nullptr && node == node2->get_Right())
//     {
//         node = node2;
//         node2 = node2->get_Parent();
//     }
//     return node2;
// }

// Red_Black_Node* Red_Black_Tree::predecessor(Red_Black_Node* node)
// {
//     if (node->get_Left() != nullptr)
//     {
//         return minimum(node->get_Left());
//     }

//     Red_Black_Node* node2 = node->get_Parent();
//     while (node2 != nullptr && node == node2->get_Left())
//     {
//         node = node2;
//         node2 = node2->get_Parent();
//     }
//     return node2;
// }

// void Red_Black_Tree::LeftRotate(Red_Black_Node* node)
// {
//     Red_Black_Node* node2 = node->get_Right();
//     node->set_Right(node2->get_Left());
//     if(node2->get_Left() != TNULL)
//     {
//         node->get_Left()->set_Parent(node);
//     }

//     node2->set_Parent(node->get_Parent());
//     if(node->get_Parent() == nullptr)
//     {
//         this->root = node2;
//     }
//     else if(node == node->get_Parent()->get_Left())
//     {
//         node->get_Parent()->set_Left(node2);
//     }
//     else
//     {
//         node->get_Parent()->set_Right(node2);
//     }
//     node2->set_Left(node);
//     node->set_Parent(node2);
// }

// void Red_Black_Tree::RightRotate(Red_Black_Node* node)
// {
//     Red_Black_Node* node2 = node->get_Left();
//     node->set_Left(node2->get_Right());
//     if(node2->get_Right() != TNULL)
//     {
//         node2->get_Right()->set_Parent(node);
//     }

//     node2->set_Parent(node->get_Parent());
//     if(node->get_Parent() == nullptr)
//     {
//         this->root = node2;
//     }
//     else if(node == node->get_Parent()->get_Right())
//     {
//         node->get_Parent()->set_Right(node2);
//     }
//     else
//     {
//         node->get_Parent()->set_Left(node2);
//     }
//     node2->set_Right(node);
//     node->set_Parent(node2);
// }

// void Red_Black_Tree::delete_fix(Red_Black_Node* node) //balance tree after deletion
// {
//     Red_Black_Node* node2;
//     while(node != root && node->get_colour() == 0)
//     {
//         if(node == node->get_Parent()->get_Left())
//         {
//             node2 = node->get_Parent()->get_Right();
//             if(node2->get_colour() == 1)
//             {
//                 node2->set_colour(0);
//                 node->get_Parent()->set_colour(1);
//                 LeftRotate(node->get_Parent());
//                 node2 = node->get_Parent()->get_Right();
//             }

//             if(node2->get_Left()->get_colour() == 0 && node2->get_Right()->get_colour() == 0)
//             {
//                 node2->set_colour(1);
//                 node = node->get_Parent();
//             }
//             else
//             {
//                 if(node2->get_Right()->get_colour() == 0)
//                 {
//                     node2->get_Left()->set_colour(0);
//                     node2->set_colour(1);
//                     RightRotate(node2);
//                     node2 = node->get_Parent()->get_Right();
//                 }
//                 node2->set_colour(node->get_Parent()->get_colour());
//                 node->get_Parent()->set_colour(0);
//                 node2->get_Right()->set_colour(0);
//                 LeftRotate(node->get_Parent());
//                 node = root;
//             }
//         }
//         else
//         {
//             node2 = node->get_Parent()->get_Left();
//             if(node2->get_colour() == 1)
//             {
//                 node2->set_colour(0);
//                 node->get_Parent()->set_colour(1);
//                 RightRotate(node->get_Parent());
//                 node2 = node->get_Parent()->get_Left();
//             }

//             if(node2->get_Right()->get_colour() == 0 && node2->get_Right()->get_colour() == 0)
//             {
//                 node2->set_colour(1);
//                 node = node->get_Parent();
//             }
//             else
//             {
//                 if(node2->get_Left()->get_colour() == 0)
//                 {
//                     node2->get_Right()->set_colour(0);
//                     node2->set_colour(1);
//                     LeftRotate(node2);
//                     node2 = node->get_Parent()->get_Left();
//                 }
//                 node2->set_colour(node->get_Parent()->get_colour());
//                 node->get_Parent()->set_colour(0);
//                 node2->get_Left()->set_colour(0);
//                 RightRotate(node->get_Parent());
//                 node = root;
//             }

//         }
//     }
//     node->set_colour(0);
// }

// void Red_Black_Tree::rbTransplant(Red_Black_Node* u, Red_Black_Node* v)
// {
//     if(u->get_Parent() == nullptr)
//     {
//         root = v;
//     }
//     else if(u == u->get_Parent()->get_Left())
//     {
//         u->get_Parent()->set_Left(v);
//     }
//     else
//     {
//         u->get_Parent()->set_Right(v);
//     }
//     v->set_Parent(u->get_Parent());
// }

// void Red_Black_Tree::deleteNode_helper(Red_Black_Node* node, int key)
// {
//     Red_Black_Node* z = TNULL;
//     Red_Black_Node* x;
//     Red_Black_Node* y;
//     while(node != TNULL)
//     {
//         if(node->get_value() == key)
//         {
//             z = node;
//         }

//         if (node->get_value() <= key)
//         {
//             node = node->get_Right();
//         }
//         else
//         {
//             node = node->get_Left();
//         }
//     }

//     if (z == TNULL)
//     {
//         std::cout << "Key not found in the tree" << std::endl;
//         return;
//     }

//     y = z;
//     int y_og_colour = y->get_colour();
//     if(z->get_Left() == TNULL)
//     {
//         x = z->get_Right();
//         rbTransplant(z, z->get_Right());
//     }
//     else if(z->get_Right() == TNULL)
//     {
//         x = z->get_Left();
//         rbTransplant(z, z->get_Left());
//     }
//     else
//     {
//         y = minimum(z->get_Right());
//         y_og_colour = y->get_colour();
//         x = y->get_Right();
//         if(y->get_Parent() == z)
//         {
//             x->set_Parent(y);
//         }
//         else
//         {
//             rbTransplant(y, y->get_Right());
//             y->set_Right(z->get_Right());
//             y->get_Right()->set_Parent(y);
//         }
//         rbTransplant(z, y);
//         y->set_Left(z->get_Left());
//         y->get_Left()->set_Parent(y);
//         y->set_colour(z->get_colour());
//     }
//     delete z;
//     if (y_og_colour == 0)
//     {
//         delete_fix(x);
//     }
// }

// void Red_Black_Tree::deleteNode(int key)
// {
//     deleteNode_helper(this->root, key);
// }

// void Red_Black_Tree::insert_fix(Red_Black_Node* k)
// {
//     Red_Black_Node* u;
//     while(k->get_Parent()->get_colour() == 1)
//     {
//         if(k->get_Parent() == k->get_Parent()->get_Parent()->get_Right())
//         {
//             u = k->get_Parent()->get_Parent()->get_Left();
//             if(u->get_colour() == 1)
//             {
//                 u->set_colour(0);
//                 k->get_Parent()->set_colour(0);
//                 k->get_Parent()->get_Parent()->set_colour(1);
//                 k = k->get_Parent()->get_Parent();
//             }
//             else
//             {
//                 if(k == k->get_Parent()->get_Left())
//                 {
//                     k = k->get_Parent();
//                     RightRotate(k);
//                 }
//                 k->get_Parent()->set_colour(0);
//                 k->get_Parent()->get_Parent()->set_colour(1);
//                 LeftRotate(k->get_Parent()->get_Parent());
//             }
//         }
//         else
//         {
//             u = k->get_Parent()->get_Parent()->get_Right();

//             if(u->get_colour() == 1)
//             {
//                 u->set_colour(0);
//                 k->get_Parent()->set_colour(0);
//                 k->get_Parent()->get_Parent()->set_colour(1);
//                 k = k->get_Parent()->get_Parent();
//             }
//             else
//             {
//                 if(k == k->get_Parent()->get_Right())
//                 {
//                     k = k->get_Parent();
//                     LeftRotate(k);
//                 }
//                 k->get_Parent()->set_colour(0);
//                 k->get_Parent()->get_Parent()->set_colour(1);
//                 RightRotate(k->get_Parent()->get_Parent());
//             }
//         }
//         if (k == root)
//         {
//             break;
//         }
//     }
//     root->set_colour(0);
// }

// void Red_Black_Tree::insert(int key)
// {
//     Red_Black_Node* node = new Red_Black_Node;
//     node->set_Parent(nullptr);
//     node->set_value(key);
//     node->set_Left(TNULL);
//     node->set_Right(TNULL);
//     node->set_colour(1);

//     Red_Black_Node* y = nullptr;
//     Red_Black_Node* x = this->root;

//     while (x != TNULL)
//     {
//         y = x;
//         if (node->get_value() < x->get_value())
//         {
//             x = x->get_Left();
//         }
//         else
//         {
//             x = x->get_Right();
//         }
//     }

//     node->set_Parent(y);
//     if(y == nullptr)
//     {
//         root = node;
//     }
//     else if(node->get_value() < y->get_value())
//     {
//         y->set_Left(node);
//     }
//     else
//     {
//         y->set_Right(node);
//     }

//     if (node->get_Parent() == nullptr)
//     {
//         node->set_colour(0);
//         return;
//     }

//     if(node->get_Parent()->get_Parent() == nullptr)
//     {
//         return;
//     }

//     insert_fix(node);
// }

// void Red_Black_Tree::print_helper(Red_Black_Node* root, std::string indent, bool last)
// {
//     if (root != TNULL)
//     {
//         std::cout << indent;
//         if (last)
//         {
//             std::cout << "R----";
//             indent += "   ";
//         }
//         else
//         {
//             std::cout << "L----";
//             indent += "|  ";
//         }

//         std::string scolour = root->get_colour() ? "RED" : "BLACK";
//         std::cout << root->get_value() << "(" << scolour << ")" << std::endl;
//         print_helper(root->get_Left(), indent, false);
//         print_helper(root->get_Right(), indent, true);
//     }
// }

// void Red_Black_Tree::print_tree()
// {
//     if(root)
//     {
//         print_helper(this->root, "", true);
//     }
// }

// void Red_Black_Tree::set_depths()
// {
//     set_depths_helper(this->root, 0);
// }

// void Red_Black_Tree::set_depths_helper(Red_Black_Node* node, int depth)
// {
//     if (node != TNULL)
//     {
//         node->set_depth(depth);
//         set_depths_helper(node->get_Left(), depth + 1);
//         set_depths_helper(node->get_Right(), depth + 1);
//     }
// }

#pragma once
#include <iostream>
#include "Red_Black_Node.cpp"
using namespace std;

class Red_Black_Tree
{
public:
    Red_Black_Node *root;

    void initializeNULLNode(Red_Black_Node *node, Red_Black_Node *parent)
    {
        node->set_data(0);
        node->set_parent(parent);
        node->set_left(nullptr);
        node->set_right(nullptr);
        node->set_color(0);
    }

    // Preorder
    void preOrderHelper(Red_Black_Node *node)
    {
        if (node != TNULL)
        {
            cout << node->get_data() << " ";
            preOrderHelper(node->get_left());
            preOrderHelper(node->get_right());
        }
    }

    // Inorder
    void inOrderHelper(Red_Black_Node *node)
    {
        if (node != TNULL)
        {
            inOrderHelper(node->get_left());
            cout << node->get_data() << " ";
            inOrderHelper(node->get_right());
        }
    }

    // Post order
    void postOrderHelper(Red_Black_Node *node)
    {
        if (node != TNULL)
        {
            postOrderHelper(node->get_left());
            postOrderHelper(node->get_right());
            cout << node->get_data() << " ";
        }
    }

    Red_Black_Node *searchTreeHelper(Red_Black_Node *node, int key)
    {
        if (node == TNULL || key == node->get_data())
        {
            return node;
        }

        if (key < node->get_data())
        {
            node->get_left()->set_prefered(true);
            node->get_right()->set_prefered(false);
            return searchTreeHelper(node->get_left(), key);
        }

        node->get_left()->set_prefered(false);
        node->get_right()->set_prefered(true);
        return searchTreeHelper(node->get_right(), key);
    }

    // For balancing the tree after deletion
    void deleteFix(Red_Black_Node *x)
    {
        Red_Black_Node *s;
        while (x != root && x->get_color() == 0)
        {
            if (x == x->get_parent()->get_left())
            {
                s = x->get_parent()->get_right();
                if (s->get_color() == 1)
                {
                    s->set_color(0);
                    x->get_parent()->set_color(1);
                    leftRotate(x->get_parent());
                    s = x->get_parent()->get_right();
                }

                if (s->get_left()->get_color() == 0 && s->get_right()->get_color() == 0)
                {
                    s->set_color(1);
                    x = x->get_parent();
                }
                else
                {
                    if (s->get_right()->get_color() == 0)
                    {
                        s->get_left()->set_color(0);
                        s->set_color(1);
                        rightRotate(s);
                        s = x->get_parent()->get_right();
                    }

                    s->set_color(x->get_parent()->get_color());
                    x->get_parent()->set_color(0);
                    s->get_right()->set_color(0);
                    leftRotate(x->get_parent());
                    x = root;
                }
            }
            else
            {
                s = x->get_parent()->get_left();
                if (s->get_color() == 1)
                {
                    s->set_color(0);
                    x->get_parent()->set_color(1);
                    rightRotate(x->get_parent());
                    s = x->get_parent()->get_left();
                }

                if (s->get_right()->get_color() == 0 && s->get_right()->get_color() == 0)
                {
                    s->set_color(1);
                    x = x->get_parent();
                }
                else
                {
                    if (s->get_left()->get_color() == 0)
                    {
                        s->get_right()->set_color(0);
                        s->set_color(1);
                        leftRotate(s);
                        s = x->get_parent()->get_left();
                    }

                    s->set_color(x->get_parent()->get_color());
                    x->get_parent()->set_color(0);
                    s->get_left()->set_color(0);
                    rightRotate(x->get_parent());
                    x = root;
                }
            }
        }
        x->set_color(0);
    }

    void rbTransplant(Red_Black_Node *u, Red_Black_Node *v)
    {
        if (u->get_parent() == nullptr)
        {
            root = v;
        }
        else if (u == u->get_parent()->get_left())
        {
            u->get_parent()->set_left(v);
        }
        else
        {
            u->get_parent()->set_right(v);
        }
        v->set_parent(u->get_parent());
    }

    void deleteNodeHelper(Red_Black_Node *node, int key)
    {
        Red_Black_Node *z = TNULL;
        Red_Black_Node *x;
        Red_Black_Node *y;
        while (node != TNULL)
        {
            if (node->get_data() == key)
            {
                z = node;
            }

            if (node->get_data() <= key)
            {
                node = node->get_right();
            }
            else
            {
                node = node->get_left();
            }
        }

        if (z == TNULL)
        {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->get_color();
        if (z->get_left() == TNULL)
        {
            x = z->get_right();
            rbTransplant(z, z->get_right());
        }
        else if (z->get_right() == TNULL)
        {
            x = z->get_left();
            rbTransplant(z, z->get_left());
        }
        else
        {
            y = minimum(z->get_right());
            y_original_color = y->get_color();
            x = y->get_right();
            if (y->get_parent() == z)
            {
                x->set_parent(y);
            }
            else
            {
                rbTransplant(y, y->get_right());
                y->set_right(z->get_right());
                y->get_right()->set_parent(y);
            }

            rbTransplant(z, y);
            y->set_left(z->get_left());
            y->get_left()->set_parent(y);
            y->set_color(z->get_color());
        }
        delete z;
        if (y_original_color == 0)
        {
            deleteFix(x);
        }
    }

    // For balancing the tree after insertion
    void insertFix(Red_Black_Node *k)
    {
        Red_Black_Node *u;
        while (k->get_parent()->get_color() == 1)
        {
            if (k->get_parent() == k->get_parent()->get_parent()->get_right())
            {
                u = k->get_parent()->get_parent()->get_left();
                if (u->get_color() == 1)
                {
                    u->set_color(0);
                    k->get_parent()->set_color(0);
                    k->get_parent()->get_parent()->set_color(1);
                    k = k->get_parent()->get_parent();
                }
                else
                {
                    if (k == k->get_parent()->get_left())
                    {
                        k = k->get_parent();
                        rightRotate(k);
                    }
                    k->get_parent()->set_color(0);
                    k->get_parent()->get_parent()->set_color(1);
                    leftRotate(k->get_parent()->get_parent());
                }
            }
            else
            {
                u = k->get_parent()->get_parent()->get_right();

                if (u->get_color() == 1)
                {
                    u->set_color(0);
                    k->get_parent()->set_color(0);
                    k->get_parent()->get_parent()->set_color(1);
                    k = k->get_parent()->get_parent();
                }
                else
                {
                    if (k == k->get_parent()->get_right())
                    {
                        k = k->get_parent();
                        leftRotate(k);
                    }
                    k->get_parent()->set_color(0);
                    k->get_parent()->get_parent()->set_color(1);
                    rightRotate(k->get_parent()->get_parent());
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root->set_color(0);
    }

    void printHelper(Red_Black_Node *root, string indent, bool last)
    {
        if (root != TNULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }

            string sColor = root->get_color() ? "RED" : "BLACK";
            cout << root->get_data() << "(" << sColor << ")" << endl;
            printHelper(root->get_left(), indent, false);
            printHelper(root->get_right(), indent, true);
        }
    }

    // public:
    Red_Black_Node *TNULL;
    Red_Black_Tree()
    {
        TNULL = new Red_Black_Node;
        TNULL->set_color(0);
        TNULL->set_left(nullptr);
        TNULL->set_right(nullptr);
        root = TNULL;
    }

    void preorder()
    {
        preOrderHelper(this->root);
    }

    void inorder()
    {
        inOrderHelper(this->root);
    }

    void postorder()
    {
        postOrderHelper(this->root);
    }

    Red_Black_Node *searchTree(int k)
    {
        return searchTreeHelper(this->root, k);
    }

    Red_Black_Node *minimum(Red_Black_Node *node)
    {
        while (node->get_left() != TNULL)
        {
            node = node->get_left();
        }
        return node;
    }

    Red_Black_Node *maximum(Red_Black_Node *node)
    {
        while (node->get_right() != TNULL)
        {
            node = node->get_right();
        }
        return node;
    }

    Red_Black_Node *successor(Red_Black_Node *x)
    {
        if (x->get_right() != TNULL)
        {
            return minimum(x->get_right());
        }

        Red_Black_Node *y = x->get_parent();
        while (y != TNULL && x == y->get_right())
        {
            x = y;
            y = y->get_parent();
        }
        return y;
    }

    Red_Black_Node *predecessor(Red_Black_Node *x)
    {
        if (x->get_left() != TNULL)
        {
            return maximum(x->get_left());
        }

        Red_Black_Node *y = x->get_parent();
        while (y != TNULL && x == y->get_left())
        {
            x = y;
            y = y->get_parent();
        }

        return y;
    }

    void leftRotate(Red_Black_Node *x)
    {
        Red_Black_Node *y = x->get_right();
        x->set_right(y->get_left());
        if (y->get_left() != TNULL)
        {
            y->get_left()->set_parent(x);
        }
        y->set_parent(x->get_parent());
        if (x->get_parent() == nullptr)
        {
            this->root = y;
        }
        else if (x == x->get_parent()->get_left())
        {
            x->get_parent()->set_left(y);
        }
        else
        {
            x->get_parent()->set_right(y);
        }
        y->set_left(x);
        x->set_parent(y);
    }

    void rightRotate(Red_Black_Node *x)
    {
        Red_Black_Node *y = x->get_left();
        x->set_left(y->get_right());
        if (y->get_right() != TNULL)
        {
            y->get_right()->set_parent(x);
        }
        y->set_parent(x->get_parent());
        if (x->get_parent() == nullptr)
        {
            this->root = y;
        }
        else if (x == x->get_parent()->get_right())
        {
            x->get_parent()->set_right(y);
        }
        else
        {
            x->get_parent()->set_left(y);
        }
        y->set_right(x);
        x->set_parent(y);
    }

    // Inserting a node
    void insert(int key)
    {
        Red_Black_Node *node = new Red_Black_Node;
        node->set_parent(nullptr);
        node->set_data(key);
        node->set_left(TNULL);
        node->set_right(TNULL);
        node->set_color(1);

        Red_Black_Node *y = nullptr;
        Red_Black_Node *x = this->root;

        while (x != TNULL)
        {
            y = x;
            if (node->get_data() < x->get_data())
            {
                x = x->get_left();
            }
            else
            {
                x = x->get_right();
            }
        }

        node->set_parent(y);
        if (y == nullptr)
        {
            root = node;
        }
        else if (node->get_data() < y->get_data())
        {
            y->set_left(node);
        }
        else
        {
            y->set_right(node);
        }

        if (node->get_parent() == nullptr)
        {
            node->set_color(0);
            return;
        }

        if (node->get_parent()->get_parent() == nullptr)
        {
            return;
        }

        insertFix(node);
    }

    Red_Black_Node *getRoot()
    {
        return this->root;
    }

    void deleteNode(int data)
    {
        deleteNodeHelper(this->root, data);
    }

    void printTree()
    {
        if (root)
        {
            printHelper(this->root, "", true);
        }
    }

    void setDepth_helper(Red_Black_Node *node, int depth)
    {
        if (node != TNULL)
        {
            node->set_depth(depth);
            setDepth_helper(node->get_left(), depth + 1);
            setDepth_helper(node->get_right(), depth + 1);
        }
    }

    void setDepth()
    {
        setDepth_helper(this->root, 0);
    }
};

extern "C"
{
    Red_Black_Tree *Red_Black_Tree_new() { return new Red_Black_Tree(); }

    void RBT_initializeNULLNode(Red_Black_Tree *RBT, Red_Black_Node *node, Red_Black_Node *parent) { RBT->initializeNULLNode(node, parent); }
    void RBT_preOrderHelper(Red_Black_Tree *RBT, Red_Black_Node *node) { RBT->preOrderHelper(node); }
    void RBT_inOrderHelper(Red_Black_Tree *RBT, Red_Black_Node *node) { RBT->inOrderHelper(node); }
    void RBT_postOrderHelper(Red_Black_Tree *RBT, Red_Black_Node *node) { RBT->postOrderHelper(node); }
    void RBT_deleteFix(Red_Black_Tree *RBT, Red_Black_Node *x) { RBT->deleteFix(x); }
    void RBT_rbTransplant(Red_Black_Tree *RBT, Red_Black_Node *u, Red_Black_Node *v) { RBT->rbTransplant(u, v); }
    void RBT_deleteNodeHelper(Red_Black_Tree *RBT, Red_Black_Node *node, int key) { RBT->deleteNodeHelper(node, key); }
    void RBT_insertFix(Red_Black_Tree *RBT, Red_Black_Node *k) { RBT->insertFix(k); }
    void RBT_printHelper(Red_Black_Tree *RBT, Red_Black_Node *root, string indent, bool last) { RBT->printHelper(root, indent, last); }
    void RBT_preorder(Red_Black_Tree *RBT) { RBT->preorder(); }
    void RBT_inorder(Red_Black_Tree *RBT) { RBT->inorder(); }
    void RBT_postorder(Red_Black_Tree *RBT) { RBT->postorder(); }
    void RBT_leftRotate(Red_Black_Tree *RBT, Red_Black_Node *x) { RBT->leftRotate(x); }
    void RBT_rightRotate(Red_Black_Tree *RBT, Red_Black_Node *x) { RBT->rightRotate(x); }
    void RBT_insert(Red_Black_Tree *RBT, int key) { RBT->insert(key); }
    void RBT_deleteNode(Red_Black_Tree *RBT, int data) { RBT->deleteNode(data); }
    void RBT_printTree(Red_Black_Tree *RBT) { RBT->printTree(); }
    void RBT_setDepth_helper(Red_Black_Tree *RBT, Red_Black_Node *node, int depth) { RBT->setDepth_helper(node, depth); }
    void RBT_setDepth(Red_Black_Tree *RBT) { RBT->setDepth(); }

    Red_Black_Node *RBT_searchTree(Red_Black_Tree *RBT, int k) { return RBT->searchTree(k); }
    Red_Black_Node *RBT_minimum(Red_Black_Tree *RBT, Red_Black_Node *node) { return RBT->minimum(node); }
    Red_Black_Node *RBT_maximum(Red_Black_Tree *RBT, Red_Black_Node *node) { return RBT->maximum(node); }
    Red_Black_Node *RBT_successor(Red_Black_Tree *RBT, Red_Black_Node *x) { return RBT->successor(x); }
    Red_Black_Node *RBT_predecessor(Red_Black_Tree *RBT, Red_Black_Node *x) { return RBT->predecessor(x); }
    Red_Black_Node *RBT_searchTreeHelper(Red_Black_Tree *RBT, Red_Black_Node *node, int key) { return RBT->searchTreeHelper(node, key); }
    Red_Black_Node *RBT_getRoot(Red_Black_Tree *RBT) { return RBT->getRoot(); }
};