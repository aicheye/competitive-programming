/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

#include <algorithm>
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
  int diameterOfBinaryTree(TreeNode *root) { return multiheight(root).first; }

  pair<int, int> multiheight(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }

    pair<int, int> left = multiheight(root->left);
    pair<int, int> right = multiheight(root->right);

    int d = left.second + right.second;
    int h = max(left.second, right.second) + 1;

    return {max(d, max(left.first, right.first)), h};
  }
};
// @lc code=end
