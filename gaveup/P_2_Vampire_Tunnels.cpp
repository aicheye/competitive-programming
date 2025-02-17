#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<tuple<int, int, bool>>> adj; 

int N;

ll ans;
ll vis[1602][3602];

void dfs(int node, ll dist, int sec) {
    if (node == N - 1) {
        ans = min(dist, ans);
        return;
    }

    for (tuple<int, int, int> e : adj[node]) {
        int child = get<0>(e);
        int d2 = dist + get<1>(e);
        int s2 = sec - get<1>(e) * (get<2>(e) ? 1 : 0);

        if (s2 >= 0 && vis[child][s2] > d2) {
            vis[child][s2] = d2;
            dfs(child, d2, s2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S, E;
    cin >> S >> N >> E;

    adj.resize(N+1);

    for (int i=0; i<E; i++) {
        int s, t, d;
        bool u;
        cin >> s >> t >> d >> u;

        adj[s].push_back(tuple(t, d, u));
        adj[t].push_back(tuple(s, d, u));
    }

    ans = LLONG_MAX;
    for (int i=1; i<=N; i++) for (int j=0; j<=S; j++) vis[i][j] = LLONG_MAX;

    vis[0][S] = 0;
    dfs(0, 0ll, S);

    cout << (ans != LLONG_MAX ? ans : -1) << "\n";

    return 0;
}
