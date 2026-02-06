/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int n;

  int find_pivot(const vector<int> &nums) {
    int lo = 0;
    int hi = n - 1;

    if (nums[lo] <= nums[hi]) {
      return 0;
    }

    while (lo < hi && nums[lo] > nums[hi]) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] > nums[lo]) {
        lo = mid;
      } else {
        hi = mid;
      }
    }

    return lo + 1;
  }

  int search(vector<int> &nums, int target) {
    n = nums.size();
    int pivot = find_pivot(nums);

    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      int val = nums[(mid + pivot) % n];

      if (val == target) {
        return (mid + pivot) % n;
      } else if (val < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return -1;
  }
};
// @lc code=end
