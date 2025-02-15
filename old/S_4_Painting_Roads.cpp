#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool vis[(int) 2e5 + 2];
int r[(int) 2e5 + 2];
bool b[(int) 2e5 + 2];
vector<vector<pair<int, int>>> adj;

void dfs(int node, int depth) {
    vis[node] = true;

    for (pair<int, int> e : adj[node]) {
        if (!vis[e.first]) {
            b[e.second] = depth % 2 == 0;
            r[e.second] = depth % 2 == 1;
            dfs(e.first, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    memset(vis, 0, sizeof(vis[0]) * N);
    memset(r, 0, sizeof(r[0]) * M);
    memset(b, 0, sizeof(b[0]) * M);

    adj.resize(N);
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(pair(v, i));
        adj[v].push_back(pair(u, i));
    }

    for (int i=0; i<N; i++) if (!vis[i]) dfs(i, 0);

    for (int i=0; i<M; i++) {
        if (r[i]) cout << "R";
        else if (b[i]) cout << "B";
        else cout << "G";
    }

    cout << "\n";

    return 0;
}
