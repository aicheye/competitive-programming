#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#

# @lc code=start
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        lo: int = 0
        hi: int = len(height) - 1
        left_max: int = height[lo]
        right_max: int = height[hi]
        sum: int = 0

        while hi > lo:
            if (left_max <= right_max):
              lo += 1
            if (right_max <= left_max):
              hi -= 1
            
            if (hi < lo):
              break

            left_max = max(height[lo], left_max)
            right_max = max(height[hi], right_max)

            water_level: int = min(left_max, right_max)
            lo_diff: int = water_level - height[lo]
            hi_diff: int = water_level - height[hi]

            sum += lo_diff if lo_diff > 0 else 0
            if (hi != lo):
              sum += hi_diff if hi_diff > 0 else 0

        return sum
        
# @lc code=end

