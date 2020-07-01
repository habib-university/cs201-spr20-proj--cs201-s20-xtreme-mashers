from ctypes import cdll
lib = cdll.LoadLibrary('./libRed_Black_Node.so')

class Red_Black_Node(object):
    def __init__(self):
        self.obj = lib.Red_Black_Node_new()

    def set_data(self, data: int):
        lib.RBN_set_data(self.obj, data)
    def set_parent(self, parent):
        lib.RBN_set_parent(self.obj, parent)
    def set_left(self,left):
        lib.RBN_set_left(self.obj, left)
    def set_right(self, right):
        lib.RBN_set_right(self.obj, right)
    def set_color(self, color: int):
        lib.RBN_set_color(self.obj, color)
    def set_depth(self, depth):
        lib.RBN_set_depth(self.obj, depth)
    def set_prefered(self, prefered: bool):
        lib.RBN_set_preffered(self.obj, prefered)

    def get_data(self):
        lib.RBN_get_data(self.obj)
    def get_color(self):
        lib.RBN_get_color(self.obj)
    def get_depth(self):
        lib.RBN_get_depth(self.obj)
    def get_parent(self):
        lib.RBN_get_parent(self.obj)
    def get_left(self):
        lib.RBN_set_left(self.obj)
    def get_right(self):
        lib.RBN_set_right(self.obj)
    def get_prefered(self):
        lib.RBN_get_prefered(self.obj)



