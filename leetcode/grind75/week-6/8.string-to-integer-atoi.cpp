/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

#include <climits>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int myAtoi(string s) {
    long long res = 0;
    bool pos = true;

    int n = s.length();
    int idx = 0;

    while (idx < n && s[idx] == ' ') {
      idx++;
    }

    if (idx < n && s[idx] == '-') {
      pos = false;
      idx++;
    } else if (idx < n && s[idx] == '+') {
      idx++;
    }

    while (idx < n && '0' <= s[idx] && s[idx] <= '9') {
      res *= 10;
      res += s[idx] - '0';
      idx++;

      if (pos && res > INT_MAX) {
        return INT_MAX;
      }

      if (!pos && -res < INT_MIN) {
        return INT_MIN;
      }
    }

    return res *= (pos ? 1 : -1);
  }
};
// @lc code=end
