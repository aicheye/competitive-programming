/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {

    int n = s.size();

    if (n % 2 == 1) {
      return false;
    }

    stack<int> opens;

    for (int i = 0; i < n; i++) {
      char c = s.at(i);
      switch (c) {
      case '(':
      case '[':
      case '{':
        opens.push(c);
        break;
      case ')':
      case ']':
      case '}':
        if (opens.empty()) {
          return false;
        } else if ((c == ')' && opens.top() != '(') ||
                   (c == ']' && opens.top() != '[') ||
                   (c == '}' && opens.top() != '{')) {
          return false;
        }
        opens.pop();
        break;
      }
    }

    return opens.empty();
  }
};
// @lc code=end
