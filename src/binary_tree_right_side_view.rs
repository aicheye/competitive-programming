/*
 * @lc app=leetcode id=199 lang=rust
 *
 * [199] Binary Tree Right Side View
 */

use crate::Solution;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

// @lc code=start
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res = Vec::new();

        if root.is_none() {
            return res;
        }

        let mut queue = VecDeque::new();
        queue.push_back(root.unwrap());

        while !queue.is_empty() {
            let right = queue.back().unwrap();
            res.push(right.borrow().val);

            for _ in 0..queue.len() {
                let cur = queue.pop_front().unwrap();

                if let Some(left) = cur.borrow().left.clone() {
                    queue.push_back(left);
                }
                if let Some(right) = cur.borrow().right.clone() {
                    queue.push_back(right);
                }
            }
        }

        res
    }
}
// @lc code=end
