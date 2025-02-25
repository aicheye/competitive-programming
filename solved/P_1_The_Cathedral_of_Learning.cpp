#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, a, b;
    cin >> N >> a >> b;

    if (a <= b && a % 2 == b % 2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
