/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  string addBinary(string a, string b) {
    bool carry = 0;

    int maxAB = max(a.length(), b.size());
    int al = a.length();
    int bl = b.length();

    stack<bool> one;

    for (int i = 0; i < maxAB; i++) {
      int currA = 0, currB = 0;

      if (i < al) {
        currA = a.at(al - 1 - i) - '0';
      }

      if (i < bl) {
        currB = b.at(bl - 1 - i) - '0';
      }

      int sum = currA + currB + carry;
      one.push(sum % 2);
      carry = sum >= 2;
    }

    if (carry) {
      one.push(1);
    }

    int n = one.size();

    string res(n, '0');

    for (int i = 0; i < n; i++) {
      if (one.top()) {
        res.at(i) = '1';
      }
      one.pop();
    }

    return res;
  }
};
// @lc code=end
