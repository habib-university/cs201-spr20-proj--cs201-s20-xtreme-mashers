class Node:
    def __init__(self, val, right, left):
        self._val = val
        self._right = right
        self._left = left
    
    def getRight(self) -> Node:
        return self._right

    def getLeft(self) -> Node:
        return self._left
