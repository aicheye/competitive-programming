/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
  int uniquePaths(int m, int n) {
    int dp[105][105];

    for (int i = 1; i <= m; i++) {
      dp[i][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
      dp[1][i] = 1;
    }

    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m][n];
  }
};
// @lc code=end
