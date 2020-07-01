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
    int get_color() { return color; }
    int get_depth() { return depth; }

    Red_Black_Node *get_parent() { return parent; }
    Red_Black_Node *get_left() { return left; }
    Red_Black_Node *get_right() { return right; }
    
    bool get_prefered() { return prefered; }
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

    void RBN_set_data(Red_Black_Node* RBN, int data_) { RBN->set_data(data_); }
    void RBN_set_parent(Red_Black_Node* RBN, Red_Black_Node *parent_) { RBN->set_parent(parent_); }
    void RBN_set_left(Red_Black_Node* RBN, Red_Black_Node *left_) {  RBN->set_left(left_); }
    void RBN_set_right(Red_Black_Node* RBN, Red_Black_Node *right_) {  RBN->set_right(right_); }
    void RBN_set_color(Red_Black_Node* RBN, int color_) {  RBN->set_color(color_); }
    void RBN_set_depth(Red_Black_Node* RBN, int depth_) {  RBN->set_depth(depth_); }
    void RBN_set_prefered(Red_Black_Node* RBN, bool prefered_) {  RBN->set_prefered(prefered_); }

    int RBN_get_data(Red_Black_Node* RBN) {  return RBN->get_data(); }
    int RBN_get_color(Red_Black_Node* RBN) {  return RBN->get_color(); }
    int RBN_get_depth(Red_Black_Node* RBN) {  return RBN-> get_depth();}

    Red_Black_Node *RBN_get_parent(Red_Black_Node* RBN) {  return RBN->get_parent(); }
    Red_Black_Node *RBN_get_left(Red_Black_Node* RBN) {  return RBN->get_left(); }
    Red_Black_Node *RBN_get_right(Red_Black_Node* RBN) {  return RBN->get_right(); }
    
    bool RBN_get_prefered(Red_Black_Node* RBN) {  return RBN->get_prefered(); }
    


};