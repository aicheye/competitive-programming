/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
  int climbStairs(int n) {
    int ways1 = 1;
    int ways2 = 2;

    if (n <= 2) {
      return n;
    }

    int total;

    for (int i = 3; i <= n; i++) {
      total = ways1 + ways2;
      ways1 = ways2;
      ways2 = total;
    }

    return total;
  }
};
// @lc code=end
