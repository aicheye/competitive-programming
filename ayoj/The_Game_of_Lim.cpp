#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool win(ll N, ll K) {
    if (N == 1) return false;

    for (int i=1; i<=K && N-i >=0; i++)
        if (!win(N-i, K)) return true;
    
    return false;
}

int main() {
    ll N, K;
    cin >> N >> K;
    
    cout << (win(N, K) ? "YES\n" : "NO\n");
}
