/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (const auto &edge : prerequisites) {
      adj[edge[1]].push_back(edge[0]);
      inDegree[edge[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    int processedCount = 0;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      processedCount++;
      
      for (int neighbor : adj[curr]) {
        if (--inDegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    return processedCount == numCourses;
  }
};
// @lc code=end
