#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int, int>> dirs {
    pair(1, 0),
    pair(0, 1),
    pair(-1, 0),
    pair(0, -1),
    pair(1, 1),
    pair(-1, 1),
    pair(-1, -1),
    pair(1, -1)
};

vector<vector<int>> perp {
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2},
    {5, 7},
    {4, 6},
    {5, 7},
    {4, 6}
};

string query;
int R, C;
char grid[102][102];

int ans;

void search(int r, int c, int curr, int d=-1, bool turned=false) {
    if (curr == query.size() - 1) {
        ans++;
        return;
    }

    int r2, c2;
    vector<pair<int, bool>> sd;

    if (d == -1) for (int i=0; i<8; i++) sd.push_back(pair(i, false));

    else {
        sd.push_back(pair(d, turned));
        if (!turned) for (int i : perp[d]) sd.push_back(pair(i, true));
    }

    for (pair<int, bool> pair : sd) {
        int i = pair.first;
        bool t = pair.second;

        r2 = r + dirs[i].first;
        c2 = c + dirs[i].second;
        if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C)
            if (grid[r2][c2] == query.at(curr + 1))
                search(r2, c2, curr + 1, i, t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> query;
    cin >> R >> C;
    for (int i=0; i<R; i++) for (int j=0; j<C; j++) 
        cin >> grid[i][j];

    ans = 0;
    for (int i=0; i<R; i++) for (int j=0; j<C; j++) 
        if (grid[i][j] == query.at(0)) search(i, j, 0);

    cout << ans << "\n";

    return 0;
}
