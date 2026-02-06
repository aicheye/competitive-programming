/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;
    vector<int> curr;
    combinationSum(candidates, target, res, curr, 0);
    return res;
  }

  void combinationSum(vector<int> &candidates, int target,
                      vector<vector<int>> &res, vector<int> &curr, int start) {
    if (target == 0) {
      res.push_back(curr);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      if (candidates[i] > target) {
        break;
      }

      curr.push_back(candidates[i]);
      combinationSum(candidates, target - candidates[i], res, curr, i);
      curr.pop_back();
    }
  }
};
// @lc code=end
