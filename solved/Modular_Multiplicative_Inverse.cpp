#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll __int128_t

__int128 read() {
    __int128 x = 0, sgn = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * sgn;
}

void print(__int128 x) {
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x > 9) print(x / 10);
    cout << (char) (x % 10 + '0');
}


ll gcd(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1;
    ll g = gcd(b%a, a, &x1, &y1);
    
    *x = y1 - (b/a) * x1;
    *y = x1;

    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    N = read();
    M = read();

    ll x, y;
    gcd(N, M, &x, &y);

    print((x % M + M) % M);
    cout << "\n";

    return 0;
}
