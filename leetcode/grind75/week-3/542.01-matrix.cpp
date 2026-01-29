/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

#include <queue>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dists = vector<vector<int>>(n, vector<int>(m, -1));

    queue<pair<int, int>> bfs;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 0) {
          dists[i][j] = 0;
          bfs.push(make_pair(i, j));
        }
      }
    }

    while (bfs.size()) {
      pair<int, int> cur = bfs.front();
      bfs.pop();

      for (pair<int, int> dir : dirs) {
        pair<int, int> child =
            make_pair(cur.first + dir.first, cur.second + dir.second);

        if (child.first < 0 || child.first >= n || child.second < 0 ||
            child.second >= m) {
          continue;
        }

        if (dists[child.first][child.second] >= 0) {
          continue;
        }

        dists[child.first][child.second] = dists[cur.first][cur.second] + 1;
        bfs.push(child);
      }
    }

    return dists;
  }
};
// @lc code=end
