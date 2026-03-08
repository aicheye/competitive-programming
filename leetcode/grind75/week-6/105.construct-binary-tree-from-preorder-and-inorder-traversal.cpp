/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

#include <unordered_map>
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
  unordered_map<int, int> inorder_idx;

  TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
    int n = inorder.size();
    inorder_idx.clear();

    for (size_t i = 0; i < n; i++) {
      inorder_idx[inorder[i]] = i;
    }

    return buildTree(preorder, 0, n, 0, n);
  }

  TreeNode *buildTree(const vector<int> &p, int start, int end, int root,
                      const int &n) {
    if (start >= end || root >= n) {
      return nullptr;
    }

    int val = p[root];
    int in_idx = inorder_idx[val];

    int left_size = in_idx - start;

    TreeNode *left = buildTree(p, start, in_idx, root + 1, n);
    TreeNode *right = buildTree(p, in_idx + 1, end, root + 1 + left_size, n);

    return new TreeNode(val, left, right);
  }
};
// @lc code=end
