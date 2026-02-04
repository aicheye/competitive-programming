/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> operands;

    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
          tokens[i] == "/") {
        int arg1 = operands.top();
        operands.pop();
        int arg2 = operands.top();
        operands.pop();
        if (tokens[i] == "+") {
          operands.push(arg2 + arg1);
        } else if (tokens[i] == "-") {
          operands.push(arg2 - arg1);
        } else if (tokens[i] == "*") {
          operands.push(arg2 * arg1);
        } else {
          operands.push(arg2 / arg1);
        }
      } else {
        operands.push(stoi(tokens[i]));
      }
    }

    return operands.top();
  }
};
// @lc code=end
