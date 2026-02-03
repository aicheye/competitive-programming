/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <algorithm>
#include <array>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
      lastIndex[i] = -1;
    }

    int left = 0;
    int res = 0;

    for (int right = 0; right < s.size(); ++right) {
      unsigned char c = s[right];
      if (lastIndex[c] >= left) {
        left = lastIndex[c] + 1;
      }
      lastIndex[c] = right;
      res = max(res, right - left + 1);
    }

    return res;
  }
};
// @lc code=end
