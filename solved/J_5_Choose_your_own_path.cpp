#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> adj;
    adj.resize(N);

    bool end[(int) 1e4 + 2];
    memset(end, 0, sizeof(end));

    for (int u=0; u<N; u++) {
        int M;
        cin >> M;

        if (M == 0) end[u] = true;
        while (M--) {
            int v;
            cin >> v;
            v--;
            adj[u].push_back(v);
        }
    }

    // bfs
    bool vis[(int) 1e4 + 2];
    memset(vis, 0, sizeof(vis));

    queue<pair<int, int>> queue;
    queue.push(pair(0, 0));
    vis[0] = true;

    int ans1 = 0;
    int ans2 = -1;

    while (!queue.empty()) {
        int node = queue.front().first;
        int depth = queue.front().second;
        queue.pop();
        ans1++;

        if (end[node] && ans2 == -1) ans2 = depth + 1;

        for (int child : adj[node]) {
            if (!vis[child]) {
                queue.push(pair(child, depth + 1));
                vis[child] = true;
            }
        }
    }

    cout << ((ans1 == N) ? "Y" : "N") << "\n";
    cout << ans2;

    return 0;
}
