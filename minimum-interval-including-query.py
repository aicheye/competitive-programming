import heapq
from typing import Dict, List, Tuple


class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        ans: Dict[int, int] = {}
        out: List[int] = []
        
        intervals.sort(key=lambda x: x[0])
        sorted = queries.copy()
        sorted.sort()

        pq: List[Tuple[int, int, int]] = []
        i: int = 0
        
        for q in sorted:
            while intervals[i][0] <= q:
                heapq.heappush(pq, (intervals[i][1] - intervals[i][0] + 1, intervals[i][0], intervals[i][1]))
            if not pq:
                ans[q] = -1
            else:
                cur = heapq.heappop(pq)
                while cur[2] < q and pq:
                    cur = heapq.heappop(pq)
                if not pq:
                    ans[q] = -1
                else:
                    ans[q] = cur[0]
        
        print(queries, ans)

        for q in queries:
            out.append(ans[q])

        return out
