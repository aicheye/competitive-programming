/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> curr;
    permute(nums, res, curr);
    return res;
  }

  void permute(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr) {
    if (nums.empty()) {
      res.push_back(curr);
    }

    for (int i = 0; i < nums.size(); i++) {
      curr.push_back(nums[i]);
      nums.erase(nums.begin() + i);
      permute(nums, res, curr);
      nums.insert(nums.begin() + i, curr.back());
      curr.pop_back();
    }
  }
};
// @lc code=end
