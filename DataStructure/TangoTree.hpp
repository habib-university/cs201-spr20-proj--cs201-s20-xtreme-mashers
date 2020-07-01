#pragma once
#include "Tango_subtree.hpp"
#include <iostream>
#include <stack>
using namespace std;

class TangoTree
{
private:
    Tango_subtree *main_tree = new Tango_subtree();

public:
    TangoTree(){};
    ~TangoTree(){};
    void Construction(Red_Black_Tree *ref_tree)
    {
        ref_tree->setDepth();
        stack<Red_Black_Node *> preffered;
        stack<Red_Black_Node *> not_preffered;
        Red_Black_Node *TNULL_ = ref_tree->TNULL;

        preffered.push(ref_tree->getRoot());
        Tango_subtree *subtree = new Tango_subtree();
        Red_Black_Node *x = nullptr;
        while (preffered.empty() == false && not_preffered.empty() == false)
        {
            if (preffered.empty() == false)
            {
                x = preffered.top();
                preffered.pop();
                if (x->get_left() != TNULL_)
                {
                    if (x->get_left()->get_prefered() == true)
                    {
                        preffered.push(x->get_left());
                    }
                    else
                    {
                        not_preffered.push(x->get_left());
                    }
                }

                if (x->get_right() != TNULL_)
                {
                    if (x->get_right()->get_prefered() == true)
                    {
                        preffered.push(x->get_left());
                    }
                    else
                    {
                        not_preffered.push(x->get_left());
                    }
                }

                subtree->insert(x);
            }
            else
            {
                subtree->getRoot()->set_isRoot(true);
                main_tree->hang(subtree->getRoot());

                subtree = new Tango_subtree();
                x = not_preffered.top();
                not_preffered.pop();
                if (x->get_left() != TNULL_)
                {
                    if (x->get_left()->get_prefered() == true)
                    {
                        preffered.push(x->get_left());
                    }
                    else
                    {
                        not_preffered.push(x->get_left());
                    }
                }

                if (x->get_right() != TNULL_)
                {
                    if (x->get_right()->get_prefered() == true)
                    {
                        preffered.push(x->get_left());
                    }
                    else
                    {
                        not_preffered.push(x->get_left());
                    }
                }
            }
        }
    }

};