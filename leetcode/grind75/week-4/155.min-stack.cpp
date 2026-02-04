/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <stack>

using namespace std;

// @lc code=start
class MinStack {
public:
  stack<int> vals;
  stack<int> mins;

  MinStack() {}

  void push(int val) {
    vals.push(val);
    if (mins.empty()) {
      mins.push(val);
    } else {
      mins.push(min(val, mins.top()));
    }
  }

  void pop() {
    mins.pop();
    vals.pop();
  }

  int top() { return vals.top(); }

  int getMin() { return mins.top(); }
};
// @lc code=end
