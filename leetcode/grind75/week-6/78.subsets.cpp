/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> curr;
    vector<vector<int>> powerset;
    subsets(nums, 0, nums.size(), curr, powerset);
    return powerset;
  }

  void subsets(vector<int> &nums, int start, int n, vector<int> &curr,
               vector<vector<int>> &powerset) {
    powerset.push_back(curr);
    for (int i = start; i < nums.size(); i++) {
      curr.push_back(nums[i]);
      subsets(nums, i + 1, n, curr, powerset);
      curr.pop_back();
    }
  }
};
// @lc code=end
