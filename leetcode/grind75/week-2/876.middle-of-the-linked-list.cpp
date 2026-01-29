/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    int n = 1;
    for (ListNode *curr = head; curr; curr = curr->next, n++) {
      continue;
    }
    ListNode *middle = head;
    for (int i = 0; i < (n - 1) / 2; i++) {
      middle = middle->next;
    }
    return middle;
  }
};
// @lc code=end
