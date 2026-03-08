/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <cstring>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();

    // p[i][j] length i starting index j
    bool p[1005][1005] = {0};

    // set p[0] and p[1] to true
    memset(p, true, 2010);

    int max_len = 1;
    int idx = 0;

    bool has_palindrome = true;

    // odds
    for (int i = 3; i <= n; i += 2) {
      if (!has_palindrome) {
        break;
      }
      has_palindrome = false;

      for (int j = 0; j <= n - i; j++) {
        if (p[i - 2][j + 1] && s[j] == s[j + i - 1]) {
          p[i][j] = true;
          has_palindrome = true;
          if (i > max_len) {
            max_len = i;
            idx = j;
          }
        }
      }
    }

    has_palindrome = true;

    // evens
    for (int i = 2; i <= n; i += 2) {
      if (!has_palindrome) {
        break;
      }
      has_palindrome = false;

      for (int j = 0; j <= n - i; j++) {
        
        if (p[i - 2][j + 1] && s[j] == s[j + i - 1]) {
          p[i][j] = true;
          has_palindrome = true;
          if (i > max_len) {
            max_len = i;
            idx = j;
          }
        }
      }
    }

    return s.substr(idx, max_len);
  }
};
// @lc code=end
