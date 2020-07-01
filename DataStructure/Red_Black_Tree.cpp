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