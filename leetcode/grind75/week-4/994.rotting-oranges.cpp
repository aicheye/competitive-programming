/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int res = 0, fresh = 0;
    queue<pair<int, int>> bfs;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        switch (grid[i][j]) {
        case 1:
          fresh++;
          break;
        case 2:
          bfs.push({i * n + j, 0});
          break;
        }
      }
    }

    while (!bfs.empty()) {
      int cur = bfs.front().first;
      int depth = bfs.front().second;
      bfs.pop();

      int x = cur / n;
      int y = cur % n;

      for (pair<int, int> dir : dirs) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx < 0 || nx >= m) {
          continue;
        }

        if (ny < 0 || ny >= n) {
          continue;
        }

        if (grid[nx][ny] != 1) {
          continue;
        }

        grid[nx][ny] = 2;
        res = depth + 1;
        fresh--;
        bfs.push({nx * n + ny, depth + 1});
      }
    }

    if (fresh > 0) {
      return -1;
    }

    return res;
  }
};
// @lc code=end
