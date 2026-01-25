#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int T, G;
vector<pair<int, int>> matchups;
int ans;

void dfs(int idx, int* table) {
    if (idx == 6 - G) {
        vector<int> firsts;
        firsts.push_back(0);
        for (int t=1; t<4; t++) {
            if (table[t] > table[firsts[0]]) {
                firsts.clear();
                firsts.push_back(t);
            }
            else if (table[t] == table[firsts[0]]) firsts.push_back(t);
        }
        if (firsts.size() == 1 && firsts[0] == T) ans++;
        return;
    }

    int next[4];
    for (int i=0; i<4; i++) next[i] = table[i];

    next[matchups[idx].first] += 3;
    dfs(idx + 1, next);
    next[matchups[idx].first] -= 3;

    next[matchups[idx].second] += 3;
    dfs(idx + 1, next);
    next[matchups[idx].second] -= 3;

    next[matchups[idx].first]++;
    next[matchups[idx].second]++;
    dfs(idx + 1, next);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    matchups.push_back(pair(0, 1));
    matchups.push_back(pair(0, 2));
    matchups.push_back(pair(0, 3));
    matchups.push_back(pair(1, 2));
    matchups.push_back(pair(1, 3));
    matchups.push_back(pair(2, 3));

    int scores[4];
    for (int i=0; i<4; i++) scores[i] = 0;

    cin >> T >> G;
    T--;

    for (int i=0; i<G; i++) {
        int A, B, Sa, Sb;
        cin >> A >> B >> Sa >> Sb;
        A--; B--;

        if (Sa > Sb) scores[A] += 3;
        else if (Sa < Sb) scores[B] += 3;
        else {
            scores[A]++;
            scores[B]++;
        }

        matchups.erase(find(
            matchups.begin(), 
            matchups.end(), 
            pair(min(A, B), max(A, B)))
        );
    }
    
    ans = 0;
    dfs(0, scores);
    cout << ans << "\n";

    return 0;
}
