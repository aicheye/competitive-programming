#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair<int, int> next(pair<int, int> p) {
    if (p == pair(1, 0)) return pair(0, 1);
    else if (p == pair(0, 1)) return pair(-1, 0);
    else if (p == pair(-1, 0)) return pair(0, -1);
    else return pair(1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int idx[102][2] = {{0}};

    int curr = 1;
    int length = 2;
    bool turned = false;
    pair<int, int> d = pair(1, 0);

    int last[2] = {0, 0};
    idx[x][0] = last[0];
    idx[x][1] = last[1];

    int lo[2] = {0, 0};
    int hi[2] = {0, 0};

    for (int i=x+1; i<=y; i++) {
        last[0] += d.first;
        last[1] += d.second;
        lo[0] = min(last[0], lo[0]);
        lo[1] = min(last[1], lo[1]);

        idx[i][0] = last[0];
        idx[i][1] = last[1];

        if (++curr == length) {
            if (turned) length++;

            turned = !turned;
            d = next(d);
            curr = 1;
        }
    }

    int spiral[102][102] = {{0}};
    int cols[102] = {0};

    for (int i=x; i<=y; i++) {
        idx[i][0] -= lo[0];
        idx[i][1] -= lo[1];
        hi[0] = max(idx[i][0], hi[0]);
        hi[1] = max(idx[i][1], hi[1]);
        spiral[idx[i][0]][idx[i][1]] = i;
        cols[idx[i][1]] = max(
            (int) to_string(i).size(), 
            cols[idx[i][1]]
        );
    }

    for (int i=0; i<=hi[0]; i++) {
        for (int j=0; j<=hi[1]; j++) {
            cout << setw(cols[j]) << right << (
                spiral[i][j] == 0 ? "" : to_string(spiral[i][j])
            );
            if (j != hi[1]) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
