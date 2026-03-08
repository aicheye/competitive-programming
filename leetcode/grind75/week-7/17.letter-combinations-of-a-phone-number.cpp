/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  const vector<vector<string>> map = {{"a", "b", "c"}, {"d", "e", "f"},
                                      {"g", "h", "i"}, {"j", "k", "l"},
                                      {"m", "n", "o"}, {"p", "q", "r", "s"},
                                      {"t", "u", "v"}, {"w", "x", "y", "z"}};

  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string curr;
    int n = digits.size();
    letterCombinations(digits, 0, curr, res, n);
    return res;
  }

  void letterCombinations(const string &digits, const int i, string &curr,
                          vector<string> &res, const int &n) {
    if (i >= n) {
      res.push_back(curr);
      return;
    }

    for (string c : map[digits[i] - '2']) {
      curr += c;
      letterCombinations(digits, i + 1, curr, res, n);
      curr.pop_back();
    }
  }
};
// @lc code=end
