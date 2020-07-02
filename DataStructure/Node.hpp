template <class T>
class Node
{
private:
    T _val;
    Node *_left;
    Node *_right;
    int _depth;
    Node *_preferedchild = nullptr;

public:
    Node(T &val, Node *left, Node *right)
    {
        _val = val;
        _left = left;
        _right = right;
        _preferedchild = nullptr;
    }
    ~Node();
    Node *getRight(){ return _right; }
    Node *getLeft(){return _left; }
    void setRight(Node *right){ _right = right;}
    void setLeft(Node *left){_left = left;}
    int getDepth(){return _depth;}
    void setDepth(int depth)
    {
        _depth = depth;
    }
    Node *getPreferedchild(){ return _preferedchild;  }
    void setPreferedchild(Node *preferedchild){ _preferedchild = preferedchild;}
    T getVal(){ return _val;}
};

