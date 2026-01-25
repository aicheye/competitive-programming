from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        node = root
        count = 0

        while True:
            while node:
                stack.append(node)
                node = node.left

            node = stack.pop()
            count += 1
            if count == k:
                return node.val

            node = node.right
