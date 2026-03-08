/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<int> degree = vector<int>(n, 0);
    vector<vector<int>> adj = vector<vector<int>>(n);

    for (const vector<int> &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
      degree[edge[0]]++;
      degree[edge[1]]++;
    }

    queue<int> leaves;

    for (int i = 0; i < n; i++) {
      if (degree[i] <= 1) {
        leaves.push(i);
      }
    }

    while (n > 2) {
      int s = leaves.size();
      n -= s;
      for (int i = 0; i < s; i++) {
        int leaf = leaves.front();
        leaves.pop();

        for (int child : adj[leaf]) {
          if (--degree[child] == 1) {
            leaves.push(child);
          }
        }
      }
    }

    vector<int> res;
    while (!leaves.empty()) {
      res.push_back(leaves.front());
      leaves.pop();
    }

    return res;
  }
};
// @lc code=end
