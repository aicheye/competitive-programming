/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int freq[26] = {0};
    int window[26] = {0};

    for (char c : p) {
      freq[c - 'a']++;
    }

    int n = p.size();
    int m = s.size();

    vector<int> res;

    for (int i = 0; i < m; i++) {
      window[s[i] - 'a']++;
      if (i >= n) {
        window[s[i - n] - 'a']--;
      }

      bool eq = true;
      for (int j = 0; j < 26; j++) {
        if (freq[j] != window[j]) {
          eq = false;
        }
      }

      if (eq) {
        res.push_back(i - n + 1);
      }
    }

    return res;
  }
};
// @lc code=end
