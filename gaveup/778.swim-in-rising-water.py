#
# @lc app=leetcode id=778 lang=python3
#
# [778] Swim in Rising Water
#


# @lc code=start
from collections import deque


class Solution(object):
    dp = []
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    n = 0

    def swimInWater(self, grid):
        self.n = len(grid)

        for i in range(self.n):
            self.dp.append([])
            for _ in range(self.n):
                self.dp[i].append(float("inf"))

        self.bfs(grid)

        return self.dp[self.n - 1][self.n - 1]

    def bfs(self, grid):
        queue = deque()

        queue.append((0, 0))
        self.dp[0][0] = grid[0][0]

        while queue:
            curr = queue.popleft()

            for dir in self.dirs:
                child = (curr[0] + dir[0], curr[1] + dir[1])
                if (
                    child[0] >= 0
                    and child[0] < self.n
                    and child[1] >= 0
                    and child[1] < self.n
                ):
                    if (
                        max(self.dp[curr[0]][curr[1]], grid[child[0]][child[1]])
                        < self.dp[child[0]][child[1]]
                    ):
                        self.dp[child[0]][child[1]] = max(
                            self.dp[curr[0]][curr[1]], grid[child[0]][child[1]]
                        )
                        queue.append(child)


if __name__ == "__main__":
    grid = [[0, 3], [1, 2]]

    sol = Solution()
    print(sol.swimInWater(grid))


# @lc code=end
