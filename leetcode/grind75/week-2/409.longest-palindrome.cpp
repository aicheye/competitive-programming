/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
  int longestPalindrome(string s) {
    int odds = 0;
    int chars = 0;

    bool odd[52];

    for (char c : s) {
      int i;
      if ('a' <= c && c <= 'z') {
        i = c - 'a';
      } else {
        i = 26 + c - 'A';
      }

      odd[i] = !odd[i];

      if (odd[i]) {
        odds++;
      } else {
        chars += 2;
        odds--;
      }
    }

    return chars + (odds ? 1 : 0);
  }
};
// @lc code=end
