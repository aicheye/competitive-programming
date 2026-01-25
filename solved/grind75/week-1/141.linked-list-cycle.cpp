/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) {
      return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast != slow) {
      slow = slow->next;
      if (fast->next) {
        fast = fast->next->next;
      } else {
        fast = fast->next;
      }
    }

    return fast && fast == slow;
  }
};
// @lc code=end
