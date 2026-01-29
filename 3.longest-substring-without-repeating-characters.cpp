/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int n = s.size();
    int res = 0;

    // seen[i][j][c] represents whether c is in s.substr(j, i)
    vector<vector<unordered_map<char, bool>>> seen =
        vector<vector<unordered_map<char, bool>>>(
            n + 1, vector<unordered_map<char, bool>>(n + 1));

    // valid[i][j] represents whether s.substr(j, i) is valid
    vector<vector<bool>> valid =
        vector<vector<bool>>(n + 1, vector<bool>(n + 1));

    for (int len = 1; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        if (len == 1) {
          seen[len][i][s.at(i)] = true;
          valid[len][i] = true;
          res = len;
          continue;
        }

        const char c1 = s.at(i);
        const char c2 = s.at(i + len - 1);

        if ((len - 2 > 1 && !valid[len - 2][i + 1]) || c1 == c2 ||
            seen[len - 2][i + 1][c1] || seen[len - 2][i + 1][c2]) {
          valid[len][i] = false;
          continue;
        }

        cout << c1 << " " << c2 << " " << len << " " << i << endl;

        seen[len][i] = seen[len - 2][i + 1];
        seen[len][i][c1] = true;
        seen[len][i][c2] = true;
        valid[len][i] = true;
        res = len;
      }
    }

    return res;
  }
};
// @lc code=end
