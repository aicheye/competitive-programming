/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <stack>

using namespace std;

// @lc code=start
class MyQueue {
public:
  stack<int> forward, reverse;
  bool reversed = false;

  MyQueue() {}

  void swap() {
    stack<int> *curr, *other;

    if (reversed) {
      curr = &reverse;
      other = &forward;
    } else {
      curr = &forward;
      other = &reverse;
    }

    while (curr->size()) {
      other->push(curr->top());
      curr->pop();
    }

    stack<int> *temp = curr;
    curr = other;
    other = temp;

    reversed = !reversed;
  }

  void push(int x) {
    if (reversed) {
      swap();
    }

    forward.push(x);
  }

  int pop() {
    if (!reversed) {
      swap();
    }

    int front = reverse.top();
    reverse.pop();
    return front;
  }

  int peek() {
    if (!reversed) {
      swap();
    }

    return reverse.top();
  }

  bool empty() {
    if (reversed) {
      return reverse.empty();
    }

    return forward.empty();
  }
};
// @lc code=end
