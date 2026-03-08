/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    short sum = 0;
    for (const int num : nums) {
      sum += num;
    }

    if (sum % 2 == 1) {
      return false;
    }

    short target = sum / 2;

    bool dp[10005] = {0};
    dp[0] = true;

    for (const int num : nums) {
      for (short i = target - num; i >= 0; i--) {
        if (i + num == target && dp[i]) {
          return true;
        }
        dp[i + num] = dp[i + num] || dp[i];
      }
    }

    return false;
  }
};
// @lc code=end
