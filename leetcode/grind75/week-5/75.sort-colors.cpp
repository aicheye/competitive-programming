/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    for (int i = 0; i <= hi; i++) {
      switch (nums[i]) {
      case 0:
        swap(nums[lo], nums[i]);
        lo++;
        break;
      case 2:
        swap(nums[i], nums[hi]);
        hi--;
        i--;
        break;
      }
    }
  }
};
// @lc code=end
