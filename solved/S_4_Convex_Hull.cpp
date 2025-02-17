#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<tuple<int, int, int>>> adj; 

int A, B;

ll ans;
ll vis[2002][202];

void dfs(int node, ll time, int hull) {
    if (node == B) {
        ans = min(time, ans);
        return;
    }

    for (tuple<int, int, int> e : adj[node]) {
        int child = get<0>(e);
        int t2 = time + get<1>(e);
        int h2 = hull - get<2>(e);

        if (h2 > 0 && vis[child][h2] > t2) {
            vis[child][h2] = t2;
            dfs(child, t2, h2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N, M;
    cin >> K >> N >> M;

    adj.resize(N+1);

    for (int i=0; i<M; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;

        adj[a].push_back(tuple(b, t, h));
        adj[b].push_back(tuple(a, t, h));
    }

    cin >> A >> B;

    ans = LLONG_MAX;
    for (int i=1; i<=N; i++) for (int j=0; j<=K; j++) vis[i][j] = LLONG_MAX;

    vis[A][K] = 0;
    dfs(A, 0ll, K);

    cout << (ans != LLONG_MAX ? ans : -1) << "\n";

    return 0;
}
