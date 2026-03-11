/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include <unordered_map>

using namespace std;

// @lc code=start
struct DLLNode {
  int key;
  int val;
  DLLNode *prev{nullptr};
  DLLNode *next{nullptr};

  DLLNode(int key, int val) : key{key}, val{val} {}
};

class LRUCache {
  DLLNode *front{nullptr};
  DLLNode *back{nullptr};

  unordered_map<int, DLLNode *> keyvals;

  int capacity;
  int size{0};

public:
  LRUCache(int capacity) : capacity{capacity} {}

  int get(int key) {
    if (keyvals.find(key) == keyvals.end()) {
      return -1;
    }

    DLLNode *newFront = keyvals[key];

    if (front == newFront) {
      return front->val;
    }

    if (back == newFront) {
      back = newFront->prev;
    }

    if (newFront->prev) {
      newFront->prev->next = newFront->next;
    }
    if (newFront->next) {
      newFront->next->prev = newFront->prev;
    }

    newFront->prev = nullptr;
    newFront->next = front;
    if (front != nullptr) {
      front->prev = newFront;
    }
    front = newFront;

    return newFront->val;
  }

  void put(int key, int value) {
    if (keyvals.find(key) != keyvals.end()) {
      DLLNode *node = keyvals[key];
      node->val = value;
      if (front != node) {
        if (back == node) {
          back = node->prev;
        }
        if (node->prev)
          node->prev->next = node->next;
        if (node->next)
          node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = front;
        if (front != nullptr)
          front->prev = node;
        front = node;
      }
      return;
    }

    if (size == capacity && back != nullptr) {
      keyvals.erase(back->key);

      DLLNode *newBack = back->prev;
      if (newBack != nullptr) {
        newBack->next = nullptr;
      }

      delete back;
      back = newBack;
      if (back == nullptr) {
        front = nullptr;
      }
    } else {
      size++;
    }

    DLLNode *newFront = new DLLNode(key, value);
    newFront->next = front;
    if (front != nullptr) {
      front->prev = newFront;
    }
    front = newFront;
    if (back == nullptr) {
      back = newFront;
    }

    keyvals[key] = newFront;
  }
};
// @lc code=end
