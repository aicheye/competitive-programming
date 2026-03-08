/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

#include <queue>
#include <vector>

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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;

    if (!root) {
      return res;
    }

    queue<TreeNode *> queue;
    queue.push(root);

    while (int size = queue.size()) {
      res.push_back(queue.back()->val);

      for (int i = 0; i < size; i++) {
        TreeNode *cur = queue.front();
        queue.pop();
        if (cur->left) {
          queue.push(cur->left);
        }
        if (cur->right) {
          queue.push(cur->right);
        }
      }
    }

    return res;
  }
};
// @lc code=end
