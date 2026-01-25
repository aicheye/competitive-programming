/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> indices;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums.at(i);
      if (indices.find(target - num) != indices.end()) {
        return {indices[target - num], i};
      }
      indices[num] = i;
    }

    return {};
  }
};

// @lc code=end
