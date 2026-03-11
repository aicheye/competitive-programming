/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

#include <algorithm>
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

    sort(begin(freq), end(freq));

    int gap = (freq[25] - 1) * n;

    for (int i = 0; i < 25; i++) {
      gap -= min(freq[25] - 1, freq[i]);
    }

    return gap < 0 ? tasks.size() : tasks.size() + gap;
  }
};
// @lc code=end
