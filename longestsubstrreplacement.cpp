#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> freq;

    for (int i = 0; i < s.length(); i++) {
      freq[s.at(i)]++;
    }

    for (string e : freq) {
    }
  }
};
