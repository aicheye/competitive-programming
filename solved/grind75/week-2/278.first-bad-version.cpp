/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

bool isBadVersion(int version);

// @lc code=start
class Solution {
public:
  int firstBadVersion(int n) {
    int lo = 1, hi = n;

    while (hi - lo > 1) {
      int mid = lo + (hi - lo) / 2;

      if (isBadVersion(mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }

    if (isBadVersion(lo)) {
      return lo;
    }

    return hi;
  }
};
// @lc code=end
