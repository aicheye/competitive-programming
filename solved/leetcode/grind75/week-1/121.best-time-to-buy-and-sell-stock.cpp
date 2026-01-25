/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int buy = prices.at(0);
    int sell = prices.at(0);
    int res = 0;

    for (const int p : prices) {
      if (p < buy) {
        buy = p;
        sell = p;
      }

      sell = max(p, sell);
      res = max(res, sell - buy);
    }

    return res;
  }
};

// @lc code=end
