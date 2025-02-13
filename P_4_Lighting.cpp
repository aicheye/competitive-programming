#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    string lights;
    cin >> lights;

    int S[(int) 1e6 + 3];
    for (int i=0; i<N; i++) S[i] = lights.at(i) - '0';

    int last = -1;
    int ans = 0;
    for (int i=0; i<N; i++) {
        if (S[i]) {
            if (last == -1 && i > K) ans += (i - 1 - K) / (2*K) + 1;
            else if (i - last - 1 > 2*K) ans += (i - last - 2 - 2*K) / (2*K) + 1;
            last = i;
        }

    }
    if (last == -1) {
        cout << (N - 1) / (2*K) + 1 << "\n";
        return 0;
    }
    if (N - last - 1 > K) ans += (N - last - 2 - K) / (2*K) + 1;

    cout << ans << "\n";
    return 0;
}
