#pragma once
#include <iostream>
#include "Red_Black_Node.hpp"
using namespace std;
typedef Red_Black_Node *NodePtr;

class Red_Black_Tree {
  private:
  NodePtr root;
  NodePtr TNULL;

  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->set_data(0);
    node->set_parent(parent);
    node->set_left(nullptr);
    node->set_right(nullptr);
    node->set_color(0);
  }

  // Preorder
  void preOrderHelper(NodePtr node) {
    if (node != TNULL) {
      cout << node->get_data() << " ";
      preOrderHelper(node->get_left());
      preOrderHelper(node->get_right());
    }
  }

  // Inorder
  void inOrderHelper(NodePtr node) {
    if (node != TNULL) {
      inOrderHelper(node->get_left());
      cout << node->get_data() << " ";
      inOrderHelper(node->get_right());
    }
  }

  // Post order
  void postOrderHelper(NodePtr node) {
    if (node != TNULL) {
      postOrderHelper(node->get_left());
      postOrderHelper(node->get_right());
      cout << node->get_data() << " ";
    }
  }

  NodePtr searchTreeHelper(NodePtr node, int key) {
    if (node == TNULL || key == node->get_data()) {
      return node;
    }

    if (key < node->get_data()) {
      return searchTreeHelper(node->get_left(), key);
    }
    return searchTreeHelper(node->get_right(), key);
  }

  // For balancing the tree after deletion
  void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->get_color() == 0) {
      if (x == x->get_parent()->get_left()) {
        s = x->get_parent()->get_right();
        if (s->get_color() == 1) {
          s->set_color(0);
          x->get_parent()->set_color(1);
          leftRotate(x->get_parent());
          s = x->get_parent()->get_right();
        }

        if (s->get_left()->get_color() == 0 && s->get_right()->get_color() == 0) {
          s->set_color(1);
          x = x->get_parent();
        } else {
          if (s->get_right()->get_color() == 0) {
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
      } else {
        s = x->get_parent()->get_left();
        if (s->get_color() == 1) {
          s->set_color(0);
          x->get_parent()->set_color(1);
          rightRotate(x->get_parent());
          s = x->get_parent()->get_left();
        }

        if (s->get_right()->get_color() == 0 && s->get_right()->get_color() == 0) {
          s->set_color(1);
          x = x->get_parent();
        } else {
          if (s->get_left()->get_color() == 0) {
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

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->get_parent() == nullptr) {
      root = v;
    } else if (u == u->get_parent()->get_left()) {
      u->get_parent()->set_left(v);
    } else {
      u->get_parent()->set_right(v);
    }
    v->set_parent(u->get_parent());
  }

  void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->get_data() == key) {
        z = node;
      }

      if (node->get_data() <= key) {
        node = node->get_right();
      } else {
        node = node->get_left();
      }
    }

    if (z == TNULL) {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->get_color();
    if (z->get_left() == TNULL) {
      x = z->get_right();
      rbTransplant(z, z->get_right());
    } else if (z->get_right() == TNULL) {
      x = z->get_left();
      rbTransplant(z, z->get_left());
    } else {
      y = minimum(z->get_right());
      y_original_color = y->get_color();
      x = y->get_right();
      if (y->get_parent() == z) {
        x->set_parent(y);
      } else {
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
    if (y_original_color == 0) {
      deleteFix(x);
    }
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->get_parent()->get_color() == 1) {
      if (k->get_parent() == k->get_parent()->get_parent()->get_right()) {
        u = k->get_parent()->get_parent()->get_left();
        if (u->get_color() == 1) {
          u->set_color(0);
          k->get_parent()->set_color(0);
          k->get_parent()->get_parent()->set_color(1);
          k = k->get_parent()->get_parent();
        } else {
          if (k == k->get_parent()->get_left()) {
            k = k->get_parent();
            rightRotate(k);
          }
          k->get_parent()->set_color(0);
          k->get_parent()->get_parent()->set_color(1);
          leftRotate(k->get_parent()->get_parent());
        }
      } else {
        u = k->get_parent()->get_parent()->get_right();

        if (u->get_color() == 1) {
          u->set_color(0);
          k->get_parent()->set_color(0);
          k->get_parent()->get_parent()->set_color(1);
          k = k->get_parent()->get_parent();
        } else {
          if (k == k->get_parent()->get_right()) {
            k = k->get_parent();
            leftRotate(k);
          }
          k->get_parent()->set_color(0);
          k->get_parent()->get_parent()->set_color(1);
          rightRotate(k->get_parent()->get_parent());
        }
      }
      if (k == root) {
        break;
      }
    }
    root->set_color(0);
  }

  void printHelper(NodePtr root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
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
  Red_Black_Tree() {
    TNULL = new Red_Black_Node;
    TNULL->set_color(0);
    TNULL->set_left(nullptr);
    TNULL->set_right(nullptr);
    root = TNULL;
  }

  void preorder() {
    preOrderHelper(this->root);
  }

  void inorder() {
    inOrderHelper(this->root);
  }

  void postorder() {
    postOrderHelper(this->root);
  }

  NodePtr searchTree(int k) {
    return searchTreeHelper(this->root, k);
  }

  NodePtr minimum(NodePtr node) {
    while (node->get_left() != TNULL) {
      node = node->get_left();
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->get_right() != TNULL) {
      node = node->get_right();
    }
    return node;
  }

  NodePtr successor(NodePtr x) {
    if (x->get_right() != TNULL) {
      return minimum(x->get_right());
    }

    NodePtr y = x->get_parent();
    while (y != TNULL && x == y->get_right()) {
      x = y;
      y = y->get_parent();
    }
    return y;
  }

  NodePtr predecessor(NodePtr x) {
    if (x->get_left() != TNULL) {
      return maximum(x->get_left());
    }

    NodePtr y = x->get_parent();
    while (y != TNULL && x == y->get_left()) {
      x = y;
      y = y->get_parent();
    }

    return y;
  }

  void leftRotate(NodePtr x) {
    NodePtr y = x->get_right();
    x->set_right(y->get_left());
    if (y->get_left() != TNULL) {
      y->get_left()->set_parent(x);
    }
    y->set_parent(x->get_parent());
    if (x->get_parent() == nullptr) {
      this->root = y;
    } else if (x == x->get_parent()->get_left()) {
      x->get_parent()->set_left(y);
    } else {
      x->get_parent()->set_right(y);
    }
    y->set_left(x);
    x->set_parent(y);
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->get_left();
    x->set_left(y->get_right());
    if (y->get_right() != TNULL) {
      y->get_right()->set_parent(x);
    }
    y->set_parent(x->get_parent());
    if (x->get_parent() == nullptr) {
      this->root = y;
    } else if (x == x->get_parent()->get_right()) {
      x->get_parent()->set_right(y);
    } else {
      x->get_parent()->set_left(y);
    }
    y->set_right(x);
    x->set_parent(y);
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Red_Black_Node;
    node->set_parent(nullptr);
    node->set_data(key);
    node->set_left(TNULL);
    node->set_right(TNULL);
    node->set_color(1);

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->get_data() < x->get_data()) {
        x = x->get_left();
      } else {
        x = x->get_right();
      }
    }

    node->set_parent(y);
    if (y == nullptr) {
      root = node;
    } else if (node->get_data() < y->get_data()) {
      y->set_left(node);
    } else {
      y->set_right(node);
    }

    if (node->get_parent() == nullptr) {
      node->set_color(0);
      return;
    }

    if (node->get_parent()->get_parent() == nullptr) {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }

  void deleteNode(int data) {
    deleteNodeHelper(this->root, data);
  }

  void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
  }
};