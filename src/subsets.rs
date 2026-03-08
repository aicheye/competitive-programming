/*
 * @lc app=leetcode id=78 lang=rust
 *
 * [78] Subsets
 */

use crate::Solution;

use std::vec::Vec;

// @lc code=start
impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut cur = Vec::new();
        let mut res = Vec::new();

        Self::backtrack(&nums, 0, nums.len() as i8, &mut cur, &mut res);

        res
    }

    fn backtrack(nums: &Vec<i32>, start: i8, n: i8, cur: &mut Vec<i32>, res: &mut Vec<Vec<i32>>) {
        res.push(cur.clone());
        for i in start..n {
            cur.push(nums[i as usize]);
            Self::backtrack(nums, i + 1, n, cur, res);
            cur.pop();
        }
    }
}
// @lc code=end
