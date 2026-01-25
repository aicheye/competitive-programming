from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res: List[List[int]] = []
        comb: List[int] = []

        def backtrack(start: int, remaining: int) -> None:
            if remaining == 0:
                res.append(list(comb))
                return
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                if candidates[i] > remaining:
                    break
                comb.append(candidates[i])
                backtrack(i + 1, remaining - candidates[i])
                comb.pop()

        backtrack(0, target)
        return res
