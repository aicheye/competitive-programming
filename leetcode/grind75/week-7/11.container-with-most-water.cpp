/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxArea(vector<int> &height) {
    int lo = 0;
    int hi = height.size() - 1;

    int res = 0;

    while (lo < hi) {
      if (height[lo] < height[hi]) {
        res = max(res, height[lo] * (hi - lo));
        lo++;
      } else {
        res = max(res, height[hi] * (hi - lo));
        hi--;
      }
    }

    return res;
  }
};
// @lc code=end
