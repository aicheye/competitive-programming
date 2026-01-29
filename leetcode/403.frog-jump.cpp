/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  short bsearch(vector<int> &stones, int target) {
    int hi = stones.size();
    int lo = 0;

    while (hi >= lo) {
      int mid = (hi + lo) / 2;

      if (stones[mid] == target) {
        return mid;
      } else if (stones[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return -1;
  }

  bool canCross(vector<int> &stones) {
    vector<bool> can_reach = vector<bool>(stones.size(), false);
    vector<unordered_set<short>> jumps =
        vector<unordered_set<short>>(stones.size());

    can_reach[0] = true;

    if (stones[1] == 1) {
      can_reach[1] = true;
      jumps[1].insert(1);
    } else {
      return false;
    }

    for (short i = 1; i < stones.size() - 1; i++) {
      for (int k : jumps[i]) {
        if (stones[i] + k <= stones.back()) {
          short idx = bsearch(stones, stones[i] + k);
          if (idx >= 0) {
            can_reach[idx] = true;
            jumps[idx].insert(k);
          }
        }
        if (k > 1 && stones[i] + k - 1 <= stones.back()) {
          short idx = bsearch(stones, stones[i] + k - 1);
          if (idx >= 0) {
            can_reach[idx] = true;
            jumps[idx].insert(k - 1);
          }
        }
        if (stones[i] + k + 1 <= stones.back()) {
          short idx = bsearch(stones, stones[i] + k + 1);
          if (idx >= 0) {
            can_reach[idx] = true;
            jumps[idx].insert(k + 1);
          }
        }
      }
    }

    return can_reach[stones.size() - 1];
  }
};
// @lc code=end
