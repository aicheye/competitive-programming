/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
      if (nums[i] > 0) {
        break;
      }

      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }

      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int total = nums[i] + nums[j] + nums[k];

        if (total < 0) {
          j++;
        } else if (total > 0) {
          k--;
        } else {
          ret.push_back({nums[i], nums[j], nums[k]});
          j++;
          while (j < k && nums[j] == nums[j - 1]) {
            j++;
          }
        }
      }
    }
    return ret;
  }
};
// @lc code=end
