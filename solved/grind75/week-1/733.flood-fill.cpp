/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {

    const int fill = image[sr][sc];
    const int n = image.size();
    const int m = image[sr].size();

    if (fill == color) {
      return image;
    }

    queue<pair<int, int>> bfs;
    bfs.push(make_pair(sr, sc));
    image[sr][sc] = color;

    while (bfs.size()) {
      const pair<int, int> curr = bfs.front();
      bfs.pop();

      for (const pair<int, int> dir : dirs) {
        const pair<int, int> child =
            make_pair(curr.first + dir.first, curr.second + dir.second);

        if (child.first < 0 || child.first >= n || child.second < 0 ||
            child.second >= m) {
          continue;
        }

        if (image[child.first][child.second] == fill) {
          image[child.first][child.second] = color;
          bfs.push(child);
        }
      }
    }

    return image;
  }
};
// @lc code=end
