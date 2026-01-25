/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> freq;

    for (const char c : magazine) {
      freq[c]++;
    }

    for (const char c : ransomNote) {
      if (--freq[c] < 0) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
