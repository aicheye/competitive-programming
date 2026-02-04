/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <stack>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int n, m;

  void fill(vector<vector<char>> &grid, int x, int y) {
    for (pair<int, int> dir : dirs) {
      int nx = x + dir.first;
      int ny = y + dir.second;

      if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        continue;
      }

      if (grid[nx][ny] == '1') {
        grid[nx][ny] = 'X';
        fill(grid, nx, ny);
      }
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    m = grid.size();
    n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != '1') {
          continue;
        }

        grid[i][j] = 'X';
        fill(grid, i, j);
        ans++;
      }
    }

    return ans;
  }
};
// @lc code=end
