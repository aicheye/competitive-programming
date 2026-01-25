/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  bool validChar(char c) {
    return ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
  }

  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      const char cLeft = tolower(s.at(left));
      const char cRight = tolower(s.at(right));

      if (!validChar(cLeft)) {
        left++;
        continue;
      }

      if (!validChar(cRight)) {
        right--;
        continue;
      }

      if (cLeft != cRight) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
};
// @lc code=end
