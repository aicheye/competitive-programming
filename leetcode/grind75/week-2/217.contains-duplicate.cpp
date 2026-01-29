/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, bool> seen;
    for (const int num : nums) {
      if (seen[num]) {
        return true;
      }
      seen[num] = true;
    }
    return false;
  }
};
// @lc code=end
