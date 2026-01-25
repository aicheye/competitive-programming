/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <cmath>
#include <utility>

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
  bool isBalanced(TreeNode *root) { return height(root).first; }

  pair<bool, int> height(TreeNode *root) {
    if (!root) {
      return {true, 0};
    }

    pair<bool, int> left = height(root->left);
    pair<bool, int> right = height(root->right);

    if (!left.first || !right.first) {
      return {false, -1};
    }

    if (abs(left.second - right.second) > 1) {
      return {false, -1};
    }

    return {true, max(left.second + 1, right.second + 1)};
  }
};
// @lc code=end
