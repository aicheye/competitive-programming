#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define BIG_PRIME 998244353

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    ll squares[(int) 1e6 + 5];
    squares[0] = 0ll;
    int idx = 0;
    ll calc = 1;

    while (T--) {
        ll A, B;
        cin >> A >> B;

        ll ans = 0;

        for (int i=0; i<=idx; i++) {
            ll square = squares[i];
            if (square < A + B) {
                ll pos = square + 1;
                pos -= max(square - A, 0ll);
                pos -= max(square - B, 0ll);

                ans += pos % BIG_PRIME;
                ans %= BIG_PRIME;
            }
            else break;
        }

        while (squares[idx] < A + B) {
            ll square = squares[idx] + calc;
            calc += 2;
            squares[++idx] = square;

            if (square < A + B) {
                ll pos = square + 1;
                pos -= max(square - A, 0ll);
                pos -= max(square - B, 0ll);

                ans += pos % BIG_PRIME;
                ans %= BIG_PRIME;
            }
            else break;
        }

        cout << ans << "\n";
    }

    return 0;
}
