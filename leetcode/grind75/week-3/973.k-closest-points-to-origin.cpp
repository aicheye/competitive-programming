/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<int, int>> dists;

    for (int i = 0; i < points.size(); i++) {
      const vector<int> p = points[i];
      dists.push(make_pair(-(p[0] * p[0] + p[1] * p[1]), i));
    }

    vector<vector<int>> close;

    while (k--) {
      const pair<int, int> next = dists.top();
      close.push_back(points[next.second]);
      dists.pop();
    }

    return close;
  }
};
// @lc code=end
