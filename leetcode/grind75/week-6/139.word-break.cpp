/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
struct PrefixNode {
  PrefixNode *nexts[26] = {0};
  bool end = false;
};

struct PrefixTree {
  PrefixNode *head;

  PrefixTree() { head = new PrefixNode(); }

  void insert(string word) {
    PrefixNode *curr = head;
    for (char c : word) {
      if (!curr->nexts[c - 'a']) {
        curr->nexts[c - 'a'] = new PrefixNode;
      }
      curr = curr->nexts[c - 'a'];
    }
    curr->end = true;
  }
};

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    PrefixTree trie;
    for (const string &word : wordDict) {
      trie.insert(word);
    }

    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
      if (!dp[i]) {
        continue;
      }

      PrefixNode *curr = trie.head;

      for (int j = i; j < n; j++) {
        if (!curr->nexts[s[j] - 'a']) {
          break;
        }

        curr = curr->nexts[s[j] - 'a'];
        
        if (curr->end) {
          dp[j + 1] = true;
        }
      }
    }

    return dp[n];
  }
};
// @lc code=end
