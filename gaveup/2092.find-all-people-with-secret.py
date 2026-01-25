#
# @lc app=leetcode id=2092 lang=python3
#
# [2092] Find All People With Secret
#

from typing import List, Set

# @lc code=start
class Solution:
  def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
    insiders : Set[int] = {0, firstPerson}

    meetings.sort(key=lambda x : x[2])

    times: List[Set[List[int]]] = [set()]

    time: int = meetings[0][2]

    for meeting in meetings:
      if meeting[2] != time:
        times.append(set())
        time = meeting[2]
      times[len(times) - 1].add([meeting[0], meeting[1]])
    
    for edges in times:
      graph: List[List[int]] = [[] for _ in range(n)]
      for edge in edges:
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])

    return list(insiders)

a = Solution()
a.findAllPeople(4, [[0,2,1],[1,3,1],[4,5,1]], 3)
    
        
# @lc code=end

