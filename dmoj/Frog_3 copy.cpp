// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long

int main() {
    ll N, C, Q;
    cin >> N >> C >> Q;

    ll dp[N];
    ll h[N];

    for (int i=0; i<N; i++) {
        cin >> h[i];
    }
    
    dp[0] = 0;

    for (int j=1; j<N; j++) {
        dp[j] = LLONG_MAX;

        for (int i=0; i<j; i++) {
            dp[j] = min(dp[j], (h[j] - h[i])*(h[j] - h[i]) + C + dp[i]);
        }
    }

    while (Q--) {
        ll q;
        cin >> q;

        cout << dp[--q] << "\n";
    }

    return 0;
}
