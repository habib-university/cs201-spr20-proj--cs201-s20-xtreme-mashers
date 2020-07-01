#pragma once
#include "Tango_Tree_Node.hpp"
#include <iostream>
#include <stack>
class Tango_subtree
{
private:
    Tango_Tree_Node *root;

    void initializeNULLNode(Tango_Tree_Node *node, Tango_Tree_Node *parent)
    {
        node->set_data(0);
        node->set_parent(parent);
        node->set_left(nullptr);
        node->set_right(nullptr);
        node->set_color(0);
    }

    // Preorder
    void preOrderHelper(Tango_Tree_Node *node)
    {
        if (node != TNULL)
        {
            cout << node->get_data() << " ";
            preOrderHelper(node->get_left());
            preOrderHelper(node->get_right());
        }
    }

    // Inorder
    void inOrderHelper(Tango_Tree_Node *node)
    {
        if (node != TNULL)
        {
            inOrderHelper(node->get_left());
            cout << node->get_data() << " ";
            inOrderHelper(node->get_right());
        }
    }

    // Post order
    void postOrderHelper(Tango_Tree_Node *node)
    {
        if (node != TNULL)
        {
            postOrderHelper(node->get_left());
            postOrderHelper(node->get_right());
            cout << node->get_data() << " ";
        }
    }

    Tango_Tree_Node *searchTreeHelper(Tango_Tree_Node *node, int key)
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
    void deleteFix(Tango_Tree_Node *x)
    {
        Tango_Tree_Node *s;
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

    void rbTransplant(Tango_Tree_Node *u, Tango_Tree_Node *v)
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

    void deleteNodeHelper(Tango_Tree_Node *node, int key)
    {
        Tango_Tree_Node *z = TNULL;
        Tango_Tree_Node *x;
        Tango_Tree_Node *y;
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
    void insertFix(Tango_Tree_Node *k)
    {
        Tango_Tree_Node *u;
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

    void printHelper(Tango_Tree_Node *root, string indent, bool last)
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

public:
    Tango_Tree_Node *TNULL;
    Tango_subtree()
    {
        TNULL = new Tango_Tree_Node;
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

    Tango_Tree_Node *searchTree(int k)
    {
        return searchTreeHelper(this->root, k);
    }

    Tango_Tree_Node *minimum(Tango_Tree_Node *node)
    {
        while (node->get_left() != TNULL)
        {
            node = node->get_left();
        }
        return node;
    }

    Tango_Tree_Node *maximum(Tango_Tree_Node *node)
    {
        while (node->get_right() != TNULL)
        {
            node = node->get_right();
        }
        return node;
    }

    Tango_Tree_Node *successor(Tango_Tree_Node *x)
    {
        if (x->get_right() != TNULL)
        {
            return minimum(x->get_right());
        }

        Tango_Tree_Node *y = x->get_parent();
        while (y != TNULL && x == y->get_right())
        {
            x = y;
            y = y->get_parent();
        }
        return y;
    }

    Tango_Tree_Node *predecessor(Tango_Tree_Node *x)
    {
        if (x->get_left() != TNULL)
        {
            return maximum(x->get_left());
        }

        Tango_Tree_Node *y = x->get_parent();
        while (y != TNULL && x == y->get_left())
        {
            x = y;
            y = y->get_parent();
        }

        return y;
    }

    void leftRotate(Tango_Tree_Node *x)
    {
        Tango_Tree_Node *y = x->get_right();
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

    void rightRotate(Tango_Tree_Node *x)
    {
        Tango_Tree_Node *y = x->get_left();
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
    void insert(Red_Black_Node *n1)
    {
        Tango_Tree_Node *node = new Tango_Tree_Node;
        node->copy_traits(n1);
        node->set_parent(nullptr);
        node->set_left(TNULL);
        node->set_right(TNULL);
        node->set_color(1);

        Tango_Tree_Node *y = nullptr;
        Tango_Tree_Node *x = this->root;

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

    Tango_Tree_Node *getRoot()
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

    void hang(Tango_Tree_Node *node)
    {
        Tango_Tree_Node *y = nullptr;
        Tango_Tree_Node *x = this->root;

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
    }

    int MinD(Tango_Tree_Node* x)
    {
        stack<Tango_Tree_Node *> s1;
        int minD = 100000000;
        s1.push(x->get_left());
        s1.push(x->get_right());
        Tango_Tree_Node *node = nullptr;
        while (!s1.empty())
        {
            node = s1.top();
            s1.pop();
            if (node != TNULL)
            {
                if (node->get_depth() < minD)
                {
                    minD = node->get_depth();
                }
                s1.push(node->get_left());
                s1.push(node->get_right());
            }
        }
        return minD;
    }

    int MaxD(Tango_Tree_Node *x)
    {
        stack<Tango_Tree_Node *> s1;
        int maxD = 0;
        s1.push(x->get_left());
        s1.push(x->get_right());
        Tango_Tree_Node *node = nullptr;
        while (!s1.empty())
        {
            node = s1.top();
            s1.pop();
            if (node != TNULL)
            {
                if (node->get_depth() > maxD)
                {
                    maxD = node->get_depth();
                }
                s1.push(node->get_left());
                s1.push(node->get_right());
            }
        }
        return maxD;
    }

    int minIgnoreMinusone_(int minD, int d)
    {
        if (minD == -1)
        {
            return d;
        }

        if (d == -1)
        {
            return minD;
        }
        return std::min(minD, d);
    }

    Tango_Tree_Node* search_tree_(Tango_Tree_Node* x, int value)
    {
        if (x == TNULL || value == x->get_data())
        {
            return x;
        }

        if (value < x->get_data())
        {
            return search_tree_(x->get_left(), value);
        }
        else
        {
            return search_tree_(x->get_right(), value);
        }
    }

    bool isInThistree_(Tango_Tree_Node* n, Tango_Tree_Node* currentRoot)
    {
        if(n->get_isRoot() && n != currentRoot)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }

    void traverse_tree_(Tango_Tree_Node* x, Tango_Tree_Node* root)
    {
        if(x != TNULL && isInThistree_(x, root))
        {
            traverse_tree_(x->get_left(), root);
            traverse_tree_(x->get_right(), root);
        }
    }

    Tango_Tree_Node* min_val_tree(Tango_Tree_Node* x)
    {
        while (x->get_left() != TNULL)
        {
            x = x->get_left();
        }
        return x;
    }

    Tango_Tree_Node* max_val_tree(Tango_Tree_Node* x)
    {
        while (x->get_right() != TNULL)
        {
            x = x->get_right();
        }
        return x;
    }

    Tango_Tree_Node* getR(int d, Tango_Tree_Node* n, Tango_Tree_Node* currentRoot)
    {
        Tango_Tree_Node *r = n;
        if (n->get_right() != TNULL && !(n->get_isRoot() || n == currentRoot) && (MaxD(n->get_right()) > d || n->get_right()->get_depth() > d))
        {
            r = getR(d, n->get_left(), currentRoot);
        }
        else
        {
            if(n->get_depth() > d)
            {
                r = n;
            }

            else
            {
                r = getR(d, n->get_right(), currentRoot);
            }
            
        }
        return r;
    }

    Tango_Tree_Node* getL(int d, Tango_Tree_Node* n, Tango_Tree_Node* currentRoot)
    {
        Tango_Tree_Node *l = n;
        if (n->get_left() != TNULL && !(n->get_isRoot() || n == currentRoot) && (MaxD(n->get_left()) > d || n->get_left()->get_depth() > d))
        {
            l = getL(d, n->get_left(), currentRoot);
        }
        else
        {
            if (n->get_depth() > d)
            {
                l = n;
            }

            else
            {
                l = getR(d, n->get_right(), currentRoot);
            }
        }
        return l;
    }

    Tango_Tree_Node* siblingBound(Tango_Tree_Node* n, Tango_Tree_Node* boundingRoot)
    {
        if (n == n->get_parent()->get_left() && isInThistree_(n->get_parent()->get_left(), boundingRoot))
        {
            if(isInThistree_(n->get_parent()->get_right(), boundingRoot))
            {
                return n->get_parent()->get_right();
            }
            else
            {
                return TNULL;
            }
        }
        else
        {
            if (isInThistree_(n->get_parent()->get_left(), boundingRoot))
            {
                return n->get_parent()->get_left();
            }
            else
            {
                return TNULL;
            }
        }
    }

    Tango_Tree_Node *uncleBound(Tango_Tree_Node *n, Tango_Tree_Node *boundingRoot)
    {
        if (isInThistree_(n->get_parent(), boundingRoot))
        {
            return siblingBound(n, boundingRoot);
        }
        else
        {
            return TNULL;
        }
    }

    void updateMinMaxD(Tango_Tree_Node* n)
    {
        int minCandidate;
        if(n->get_left() != TNULL)
        {
            updateMinMaxD(n->get_left());
        }
        if(n->get_right() != TNULL)
        {
            updateMinMaxD(n->get_right());
        }
        if(n->get_left() != TNULL)
        {
            int maxFromLeft = std::max(n->get_left()->get_depth(), MaxD(n->get_left()));
            
        }
    }
};