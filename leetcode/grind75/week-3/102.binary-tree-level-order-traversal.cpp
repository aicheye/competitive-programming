/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<pair<int, TreeNode *>> bfs;
    vector<vector<int>> ret;
    int size = 0;

    bfs.push({0, root});

    while (!bfs.empty()) {
      pair<int, TreeNode *> curr = bfs.front();
      bfs.pop();

      if (curr.second != nullptr) {
        if (size <= curr.first) {
          ret.push_back(vector<int>());
          size++;
        }
        ret[curr.first].push_back(curr.second->val);
        bfs.push({curr.first + 1, curr.second->left});
        bfs.push({curr.first + 1, curr.second->right});
      }
    }

    return ret;
  }
};
// @lc code=end
