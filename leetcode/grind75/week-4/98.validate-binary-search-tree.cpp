/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

#include <algorithm>
#include <limits>
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
typedef long long ll;

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return isValidBSTBounds(root->left, numeric_limits<ll>::min(), root->val) &&
           isValidBSTBounds(root->right, root->val, numeric_limits<ll>::max());
  }

  bool isValidBSTBounds(TreeNode *root, ll lb, ll ub) {
    if (!root) {
      return true;
    }
    if (root->val >= ub || root->val <= lb) {
      return false;
    }

    return isValidBSTBounds(root->left, lb,
                            min(ub, static_cast<ll>(root->val))) &&
           isValidBSTBounds(root->right, max(lb, static_cast<ll>(root->val)),
                            ub);
  }
};
// @lc code=end
