/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> freq;

    for (char c : s) {
      freq[c]++;
    }

    for (char c : t) {
      freq[c]--;
      if (freq[c] < 0) {
        return false;
      }
    }

    for (pair<char, int> charFreq : freq) {
      if (charFreq.second != 0) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
