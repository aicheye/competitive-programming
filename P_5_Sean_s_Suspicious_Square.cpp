#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int R, C, K;
long long M, ans;

void search(int r, int c, int dir, int turns, bool first) {
    int r2, c2;
    ans %= M;
    if (turns == K) {
        //if (r == R-1 && c == C-1) ans++;
        if (r == R-1 && dir == 2) ans++;
        else if (c == C-1 && dir == 0) ans++;
    }
    else if (first) {
        r2 = r + dirs[dir][0];
        c2 = c + dirs[dir][1]; 
        if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
            search(r2, c2, dir, turns, false);
        }
    }
    else {
        for (int i=0; i<4; i++) {
            r2 = r + dirs[i][0];
            c2 = c + dirs[i][1]; 
            if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
                if (i != dir) search(r2, c2, i, turns + 1, false);
                else search(r2, c2, i, turns, false);
            }
        }
    }
}

int main() {
    cin >> R >> C >> K >> M;

    ans = 0;
    search(0, 0, 0, 0, true);
    search(0, 0, 2, 0, true);
    ans %= M;

    cout << ans << "\n";

    return 0;
}
