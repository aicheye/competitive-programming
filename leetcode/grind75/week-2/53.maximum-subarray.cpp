/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sofar = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      sofar = max(nums[i], sofar + nums[i]);
      res = max(sofar, res);
    }
    return res;
  }
};
// @lc code=end
