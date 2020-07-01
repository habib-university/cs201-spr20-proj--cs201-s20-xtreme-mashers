#pragma once
class Red_Black_Node
{
private:
    int data;
    Red_Black_Node *parent = nullptr;
    Red_Black_Node *left = nullptr;
    Red_Black_Node *right = nullptr;
    int color;
    int depth;
    bool prefered = false;

public:
    Red_Black_Node() {}
    ~Red_Black_Node() {}

    void set_data(int data_) { data = data_; }
    // void set_parent(Red_Black_Node *parent_) { parent = parent_; }
    // void set_left(Red_Black_Node *left_) { left = left_; }
    // void set_right(Red_Black_Node *right_) { right = right_; }
    // void set_color(int color_) { color = color_; }
    // void set_depth(int depth_) { depth = depth_; }
    // void set_prefered(bool prefered_) { prefered = prefered_; }

    // int get_data() { return data; }
    // Red_Black_Node *get_parent() { return parent; }
    // Red_Black_Node *get_left() { return left; }
    // Red_Black_Node *get_right() { return right; }
    // int get_color() { return color; }
    // int get_depth() { return depth; }
    // bool get_prefered() { return prefered; }
};

extern "C" {
    Red_Black_Node* Red_Black_Node_new(){ return new Red_Black_Node();}
    
    int data;
    Red_Black_Node *parent = nullptr;
    Red_Black_Node *left = nullptr;
    Red_Black_Node *right = nullptr;
    int color;
    int depth;
    bool prefered = false;

    void RBT_set_data(Red_Black_Node* RBT, int data_) { RBT->set_data(data_); }
    // void RBT_set_parent(F *parent_) { parent = parent_; }
    // void RBT_set_left(F *left_) { left = left_; }
    // void RBT_set_right(F *right_) { right = right_; }
    // void RBT_set_color(F color_) { color = color_; }
    // void RBT_set_depth(int depth_) { depth = depth_; }
    // void RBT_set_prefered(bool prefered_) { prefered = prefered_; }

    // int RBT_get_data() { return data; }
    // Red_Black_Node *RBT_get_parent() { return parent; }
    // Red_Black_Node *RBT_get_left() { return left; }
    // Red_Black_Node *RBT_get_right() { return right; }
    // int RBT_get_color() { return color; }
    // int RBT_get_depth() { return depth; }
    // bool RBT_get_prefered() { return prefered};


};