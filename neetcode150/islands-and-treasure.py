from collections import deque
from typing import Deque, List, Tuple


class node:
  def __init__(self, x: int, y: int, d: int):
     self.x = x
     self.y = y
     self.d = d
  
  def __str__(self):
     return f"({self.x}, {self.y}): {self.d}"


class Solution:
    dirs: List[Tuple[int, int]] = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    vis: List[List[int]]
    queue: Deque[node]

    def valid(self, x: int, y: int, grid: List[List[int]]):
       return x >= 0 and x < len(grid) and y >= 0 and y < len(grid[0])

    def bfs(self, grid: List[List[int]]):
      while self.queue:
          cur: node = self.queue.popleft()
          grid[cur.x][cur.y] = cur.d

          for dir in self.dirs:
             if self.valid(cur.x + dir[0], cur.y + dir[1], grid) \
              and not self.vis[cur.x + dir[0]][cur.y + dir[1]] \
              and grid[cur.x + dir[0]][cur.y + dir[1]] >= 0:
              self.queue.append(node(cur.x + dir[0], cur.y + dir[1], cur.d + 1))
              self.vis[cur.x + dir[0]][cur.y + dir[1]] = True

          
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        self.vis = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        self.queue: Deque[node] = deque()

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                   self.queue.append(node(i, j, 0))
                   self.vis[i][j] = True
        
        self.bfs(grid)
