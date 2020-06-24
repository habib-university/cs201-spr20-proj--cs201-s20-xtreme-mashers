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
    void set_parent(Red_Black_Node *parent_) { parent = parent_; }
    void set_left(Red_Black_Node *left_) { left = left_; }
    void set_right(Red_Black_Node *right_) { right = right_; }
    void set_color(int color_) { color = color_; }
    void set_depth(int depth_) { depth = depth_; }
    void set_prefered(bool prefered_) { prefered = prefered_; }

    int get_data() { return data; }
    Red_Black_Node *get_parent() { return parent; }
    Red_Black_Node *get_left() { return left; }
    Red_Black_Node *get_right() { return right; }
    int get_color() { return color; }
    int get_depth() { return depth; }
    bool get_prefered() { return prefered; }
};