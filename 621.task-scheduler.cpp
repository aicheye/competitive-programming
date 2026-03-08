/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int freq[26] = {0};

    for (const char &task : tasks) {
      freq[task - 'A']++;
    }

    int hi = 0;
    int gap = 2;
  }
};
// @lc code=end
