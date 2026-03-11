/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int n = 1;
    int res = -1;
    inorder(root, k, n, res);
    return res;
  }

  void inorder(TreeNode *root, int k, int &n, int &res) {
    if (!root || res != -1) {
      return;
    }

    inorder(root->left, k, n, res);
    if (n++ == k) {
      res = root->val;
      return;
    }
    inorder(root->right, k, n, res);
  }
};
// @lc code=end
