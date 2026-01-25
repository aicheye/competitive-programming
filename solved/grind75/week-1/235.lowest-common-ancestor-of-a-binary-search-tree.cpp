/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int big, small;
    if (p->val > q->val) {
      big = p->val;
      small = q->val;
    } else {
      big = q->val;
      small = p->val;
    }

    while (root->left || root->right) {
      if (root->val > big && root->left) {
        root = root->left;
      } else if (root->val < small && root->right) {
        root = root->right;
      } else {
        break;
      }
    }

    return root;
  }
};
// @lc code=end
