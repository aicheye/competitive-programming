/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// @lc code=start
class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }

    unordered_map<Node *, Node *> clones;
    queue<Node *> bfs;

    bfs.push(node);
    clones[node] = new Node(node->val);

    while (!bfs.empty()) {
      Node *curr = bfs.front();
      bfs.pop();

      for (Node *neighbor : curr->neighbors) {
        if (clones.find(neighbor) == clones.end()) {
          clones[neighbor] = new Node(neighbor->val);
          bfs.push(neighbor);
        }
        clones[curr]->neighbors.push_back(clones[neighbor]);
      }
    }

    return clones[node];
  }
};
// @lc code=end
