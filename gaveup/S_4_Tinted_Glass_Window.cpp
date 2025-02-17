#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    map<pair<int, int>, int> t;

    int ans = 0;

    for (int i=0; i<N; i++) {
        int xl, yt, xr, yb, ti;
        cin >> xl >> yt >> xr >> yb >> ti;

        for (int i=xl; i<xr; i++) {
            for (int j=yt; j<yb; j++) {
                if (t[pair(i, j)] < T && t[pair(i, j)] + ti >= T) ans++;
                t[pair(i, j)] += ti;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
