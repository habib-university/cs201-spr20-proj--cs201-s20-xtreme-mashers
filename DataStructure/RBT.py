from ctypes import cdll
lib = cdll.LoadLibrary('./libRed_Black_Tree.so')

class Red_Black_Tree(object):
    def __init__(self):
        self.obj = lib.Red_Black_Tree_new()

    def RBT_initializeNULLNode(self, node, parent):
        lib.RBT_initializeNULLNode(self.obj, node, parent)
    def RBT_preOrderHelper(self, node):
        lib.RBT_preOrderHelper(self.obj, node)
    def RBT_inOrderHelper(self, node):
        lib.RBT_inOrderHelper(self.obj, node)
    def RBT_postOrderHelper(self, node):
        lib.RBT_postOrderHelper(self.obj, node)
    def RBT_deleteFix(self, x):
        lib.RBT_deleteFix(self.obj, x)
    def RBT_rbTransplant(self, u, v):
        lib.RBT_rbTransplant(self.obj, u, v)
    def RBT_deleteNodeHelper(self,node,key):
        lib.RBT_deleteNodeHelper(self.obj, node, key)
    def RBT_insertFix(self,k):
        lib.RBT_insertFix(self.obj, k)
    def RBT_printHelper(self, root, indent, last):
        lib.RBT_printHelper(self.obj,root, indent, last)
    def RBT_preorder(self):
        lib.RBT_preorder(self.obj)
    def RBT_inorder(self):
        lib.RBT_inorder(self.obj)
    def RBT_postorder(self):
        lib.RBT_postorder(self.obj)
    def RBT_leftRotate(self, x):
        lib.RBT_leftRotate(self.obj, x)
    def RBT_rightRotate(self,x):
        lib.RBT_rightRotate(self.obj, x)
    def RBT_insert(self, key):
        lib.RBT_insert(self.obj, key)
    def RBT_deleteNode(self,data):
        lib.RBT_deleteNode(self.obj, data)
    def RBT_printTree(self):
        lib.RBT_printTree(self.obj)
    def RBT_setDepth_helper(self, node, depth):
        lib.RBT_setDepth(self.obj,node,depth)
    def RBT_setDepth(self):
        lib.RBT_setDepth(self.obj)
    def RBT_searchTree(self,k):
        lib.RBT_searchTree(self.obj, k)
    def RBT_minimum(self, node):
        lib.RBT_minimum(self.obj, node)
    def RBT_maximum(self, node):
        lib.RBT_maximum(self.obj, node)
    def RBT_successor(self,x):
        lib.RBT_successor(self.obj, x)
    def RBT_predecessor(self,x):
        lib.RBT_predecessor(self.obj, x)
    def RBT_searchTreeHelper(self, node, key):
        lib.RBT_searchTreeHelper(self.obj, node, key)
    def RBT_getRoot(self):
        lib.RBT_getRoot(self.obj)


