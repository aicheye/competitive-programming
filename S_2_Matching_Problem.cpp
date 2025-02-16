#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll GCDEUCLID(ll a, ll b) {
    if (a == 0) return b;
    return GCDEUCLID(b%a, a);
}

ll LCMEUCLID(ll a, ll b) {
    if (a > b) return a / GCDEUCLID(a, b) * b;
    else return b / GCDEUCLID(a, b) * a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;
    ll sSize = S.size();
    ll tSize = T.size();
    ll lcmST = LCMEUCLID(sSize, tSize);

    ll ans = 0;

    ll matchLCM = 0;
    for (ll i=0; i<lcmST; i++) {
         if (S.at(i % sSize) == T.at(i % tSize)) matchLCM++;
    }

    ll quotient = min(N * sSize, M * tSize) / lcmST;
    ll remainder = min(N * sSize, M * tSize) - quotient * lcmST;

    ans += quotient * matchLCM;

    for (ll i=0; i<remainder; i++) {
        if (S.at(i % sSize) == T.at(i % tSize)) ans++;
    }

    cout << ans << "\n";
    return 0;
}
