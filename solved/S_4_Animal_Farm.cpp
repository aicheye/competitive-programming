#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int parents[102];

pair<int, int> sortp(int a, int b) {
    return pair(max(a, b), min(a, b));
}

pair<int, int> itoe(int a, vector<int> corners) {
    return sortp(corners[a], corners[(a+1)%corners.size()]);
}

void make_set(int a) {
    parents[a] = a;
}

int find_set(int a) {
    if (parents[a] == a) return a;
    return parents[a] = find_set(parents[a]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parents[b] = a;
    }
}

ll kruskals(priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> adj) {
    ll total = 0;

    while (!adj.empty()) {
        int w = adj.top().first;
        int u = adj.top().second.first;
        int v = adj.top().second.second;

        if (find_set(u) != find_set(v)) {
            //cout << u << " <-> " << v << " : " << w << "\n";
            union_set(u, v);
            total += w;
        }

        adj.pop();
    }
    
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> adj;

    map<pair<int, int>, vector<int>> pens;
    map<pair<int, int>, int> weights;

    for (int i=0; i<M; i++) {
        int e;
        cin >> e;

        vector<int> corners;

        for (int j=0; j<e; j++) {
            int c;
            cin >> c;
            corners.push_back(c);
        }

        for (int j=0; j<e; j++) {
            int w;
            cin >> w;
            pens[itoe(j, corners)].push_back(i);
            weights[itoe(j, corners)] = w;
        }
    }

    for (int i=0; i<M; i++) make_set(i);

    for (auto const& [key, val] : pens) {
        if (val.size() == 2) {
            int w = weights[key];
            int u = val[0];
            int v = val[1];
            adj.push(pair(w, pair(u, v)));
        }
    }

    ll total = kruskals(adj);

    int meetOut = false;
    for (int u=0; u<M && !meetOut; u++) for (int v=u+1; v<M && !meetOut; v++)
        if (find_set(u) != find_set(v)) meetOut = true;
    
    adj = priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>();

    // set M: outside
    for (int i=0; i<=M; i++) make_set(i);

    for (auto const& [key, val] : pens) {
        if (val.size() == 2) {
            int w = weights[key];
            int u = val[0];
            int v = val[1];
            adj.push(pair(w, pair(u, v)));
        }
        else if (val.size() == 1) {
            int w = weights[key];
            int u = val[0];
            adj.push(pair(w, pair(u, M)));
        }
    }

    ll totalOut = kruskals(adj);

    if (meetOut) cout << totalOut << "\n";
    else cout << min(total, totalOut) << "\n";

    return 0;
}
