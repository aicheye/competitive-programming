/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <limits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp = vector<int>(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (const int coin : coins) {
        if (coin > i) {
          continue;
        }

        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};
// @lc code=end
