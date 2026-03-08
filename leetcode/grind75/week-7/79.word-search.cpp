/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<bool>> vis;

  bool exist(const vector<vector<char>> &board, const string &word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          vis = vector<vector<bool>>(m, vector<bool>(n, false));
          if (dfs(board, word, i, j, 1, m, n)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool dfs(const vector<vector<char>> &board, const string &word, int x, int y,
           int i, const int &m, const int &n) {
    if (i >= word.size()) {
      return true;
    }

    vis[x][y] = true;

    for (const vector<int> &dir : dirs) {
      int nx = x + dir[0];
      int ny = y + dir[1];

      if (0 <= nx && nx < m && 0 <= ny && ny < n && board[nx][ny] == word[i] &&
          !vis[nx][ny] && dfs(board, word, nx, ny, i + 1, m, n)) {
        return true;
      }
    }

    vis[x][y] = false;

    return false;
  }
};
// @lc code=end
