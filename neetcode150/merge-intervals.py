from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        print(intervals)
        merged: List[List[int]] = []

        idx: int = 0
        while idx < len(intervals):
            merge_start: int = intervals[idx][0]
            merge_end: int = intervals[idx][1]
            new_idx: int = idx + 1
            for i in range(idx + 1, len(intervals)):
                if intervals[i][0] > merge_end:
                    break
                else:
                    new_idx = i + 1
                    merge_end = max(merge_end, intervals[i][1])
            idx = new_idx
            merged.append([merge_start, merge_end])

        return merged
