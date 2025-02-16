#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int parent[52] = {-1};

vector<list<int>> adj;

bool added[52] = {false};

void edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    added[a] = true;
    added[b] = true;
}

int bfs(int a, int b) {
    bool vis[52] = {false};
    queue<pair<int, int>> queue;
    queue.push(pair(a, 0));
    vis[a] = true;

    bool found = false;
    while (!queue.empty() && !found) {
        int node = queue.front().first;
        int depth = queue.front().second;
        queue.pop();

        for (int f : adj[node]) {
            if (!vis[f]) {
                if (f == b) return depth + 1;
                queue.push(pair(f, depth + 1));
                vis[f] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    adj.resize(52);
    
    edge(1, 6);edge(2, 6);edge(3, 6);edge(4, 6);edge(5, 6); edge(3, 5);edge(3, 4);edge(4, 5);edge(6, 7);edge(7, 8); edge(8, 9);edge(9, 12);edge(9, 10);edge(10, 11); edge(11, 12);edge(3, 15);edge(12, 13);edge(13, 15); edge(13, 14);edge(16, 18);edge(16, 17);edge(17, 18);

    char query;
    do {
        cin >> query;
        int x, y;

        if (query == 'i') {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            added[x] = true;
            added[y] = true;
        }

        else if (query == 'd') {
            cin >> x >> y;
            if (added[x] && added[y]) {
                adj[x].erase(find(adj[x].begin(), adj[x].end(), y));
                adj[y].erase(find(adj[y].begin(), adj[y].end(), x));
            }
        }

        else if (query == 'n') {
            cin >> x;
            if (added[x]) cout << adj[x].size() << "\n";
            else cout << "0\n";
        }

        else if (query == 'f') {
            cin >> x;
            int ans = 0;

            if (added[x]) {
                for (int i=0; i<52; i++) {
                    if (bfs(x, i) == 2) ans++;
                }
            }

            cout << ans << "\n";
        }

        else if (query == 's') {
            cin >> x >> y;

            if (added[x] && added[y]) {
                int sep = bfs(x, y);
                if (sep != -1) cout << sep << "\n";
                else cout << "Not connected\n";
            }
            else cout << "Not connected\n";
        }

    } while (query != 'q');

    return 0;
}
