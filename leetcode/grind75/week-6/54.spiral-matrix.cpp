/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int left = 0;

    vector<int> res;

    while (top <= bottom && left <= right) {
      // top
      for (int x = left; x <= right; x++) {
        res.push_back(matrix[top][x]);
      }

      // right
      for (int y = top + 1; y <= bottom; y++) {
        res.push_back(matrix[y][right]);
      }

      if (top != bottom) {
        // bottom
        for (int x = right - 1; x >= left; x--) {
          res.push_back(matrix[bottom][x]);
        }
      }

      if (left != right) {
        // left
        for (int y = bottom - 1; y >= top + 1; y--) {
          res.push_back(matrix[y][left]);
        }
      }

      top++;
      right--;
      bottom--;
      left++;
    }

    return res;
  }
};
// @lc code=end
