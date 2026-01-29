/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        lo = mid + 1;
      } else if (nums[mid] > target) {
        hi = mid - 1;
      }
    }

    return -1;
  }
};
// @lc code=end
