import RBT

rbtree = RBT.Red_Black_Tree()
for i in [13, 32, 8, 12, 21, 43]:
    rbtree.RBT_insert(i)

rbtree.RBT_printTree()
