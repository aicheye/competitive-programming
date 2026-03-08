/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> parent;

  int find_set(int s) {
    if (parent[s] == s) {
      return s;
    }
    return parent[s] = find_set(parent[s]);
  }

  void union_set(int u, int v) { parent[find_set(u)] = find_set(v); }

  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }

    unordered_map<string, int> emailToId;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        const string &email = accounts[i][j];
        if (emailToId.count(email)) {
          union_set(i, emailToId[email]);
        } else {
          emailToId[email] = i;
        }
      }
    }

    unordered_map<int, vector<string>> components;
    for (auto &pair : emailToId) {
      int root = find_set(pair.second);
      components[root].push_back(pair.first);
    }

    vector<vector<string>> res;
    for (auto &pair : components) {
      sort(pair.second.begin(), pair.second.end());

      vector<string> account;
      account.reserve(pair.second.size() + 1);
      account.push_back(accounts[pair.first][0]);
      account.insert(account.end(), pair.second.begin(), pair.second.end());
      res.push_back(account);
    }

    return res;
  }
};
// @lc code=end
