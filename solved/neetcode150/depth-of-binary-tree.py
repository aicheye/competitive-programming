# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepthRec(self, this: TreeNode) -> int:
        if this.left and this.right:
            return 1 + max(self.maxDepthRec(this.left), self.maxDepthRec(this.right))
        elif this.left:
            return 1 + self.maxDepthRec(this.left)
        elif this.right:
            return 1 + self.maxDepthRec(this.right)
        else:
            return 1

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return self.maxDepthRec(root)
    