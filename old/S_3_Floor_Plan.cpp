#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dirs[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int R, C;
char grid[25+2][25+2];
bool vis[25+2][25+2];

void dfs(int r, int c, int &size) {
    vis[r][c] = true;
    size++;

    int r2, c2;
    for (int i=0; i<4; i++) {
        r2 = r + dirs[i][0];
        c2 = c + dirs[i][1];
        if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
            if (grid[r2][c2] != 'I' && !vis[r2][c2]) {
                dfs(r2, c2, size);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M >> R >> C;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> grid[i][j];
            vis[i][j] = false;
        }
    }

    vector<int> rooms;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (grid[i][j] != 'I' && !vis[i][j]) {
                int size = 0;
                dfs(i, j, size);
                rooms.push_back(size);
            }
        }
    }

    sort(rooms.begin(), rooms.end(), greater<int>());

    int count = 0;
    for (int next : rooms) {
        if (M - next >= 0) M -= next;
        else break;
        count++;
    }

    if (count == 1) cout << "1 room, ";
    else cout << count << " rooms, ";
    cout << M << " square metre(s) left over\n";

    return 0;
}
