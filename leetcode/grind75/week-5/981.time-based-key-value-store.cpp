/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class TimeMap {
public:
  unordered_map<string, vector<pair<int, string>>> store;

  TimeMap() {}

  void set(string key, string value, int timestamp) {
    store[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    if (store.find(key) == store.end()) {
      return "";
    }

    const vector<pair<int, string>> &store_key = store[key];

    int lo = 0;
    int hi = store_key.size() - 1;

    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;

      if (store_key[mid].first == timestamp) {
        return store_key[mid].second;
      } else if (store_key[mid].first < timestamp) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    if (store_key[lo].first > timestamp) {
      return "";
    }
    return store_key[lo].second;
  }
};
// @lc code=end
