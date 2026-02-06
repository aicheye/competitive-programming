/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    int start = intervals[0][0];
    int end = intervals[0][1];
    int curr = 1;

    while (curr <= n) {
      while (curr < n && intervals[curr][0] <= end) {
        end = max(end, intervals[curr][1]);
        curr++;
      }

      res.push_back({start, end});

      if (curr >= n) {
        break;
      }

      start = intervals[curr][0];
      end = intervals[curr][1];
    }

    return res;
  }
};
// @lc code=end
