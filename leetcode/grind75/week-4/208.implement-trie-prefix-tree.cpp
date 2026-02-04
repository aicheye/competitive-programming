/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
struct TrieNode {
  char val;
  bool end = false;
  TrieNode *nexts[26] = {0};

  TrieNode() {};
  TrieNode(char val_) : val(val_) {};
};

class Trie {
public:
  TrieNode *head;

  Trie() { head = new TrieNode; }

  void insert(string word) {
    TrieNode *curr = head;
    for (char c : word) {
      int i = c - 'a';
      if (curr->nexts[i] == nullptr) {
        curr->nexts[i] = new TrieNode(c);
      }
      curr = curr->nexts[i];
    }
    curr->end = true;
  }

  bool search(string word) {
    TrieNode *curr = head;
    for (char c : word) {
      int i = c - 'a';
      if (curr->nexts[i] == nullptr) {
        return false;
      }
      curr = curr->nexts[i];
    }
    return curr->end;
  }

  bool startsWith(string prefix) {
    TrieNode *curr = head;
    for (char c : prefix) {
      int i = c - 'a';
      if (curr->nexts[i] == nullptr) {
        return false;
      }
      curr = curr->nexts[i];
    }
    return true;
  }
};
// @lc code=end
