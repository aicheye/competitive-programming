/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();

    int candidate = nums.at(0);
    int count = 1;

    for (int i = 1; i < n; i++) {
      const int curr = nums.at(i);

      if (curr == candidate) {
        count++;
      } else {
        count--;
      }

      if (count == 0) {
        candidate = curr;
        count = 1;
      }
    }

    return candidate;
  }
};
// @lc code=end
