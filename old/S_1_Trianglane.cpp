#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    cin >> C;

    bool top[(int) 2e5 + 2] = {0};
    bool bot[(int) 2e5 + 2] = {0};

    int l = 0;
    for (int i=0; i<C; i++) {
        cin >> top[i];
        if (top[i]) l += 3;
    }
    for (int i=0; i<C; i++) {
        cin >> bot[i];
        if (bot[i]) l += 3;
    }

    for (int i=0; i<C; i++) {
        if (i != C - 1 && top[i] && top[i+1]) l -= 2;
        if (i != C - 1 && bot[i] && bot[i+1]) l -= 2;
        if (i % 2 == 0 && top[i] && bot[i]) l -= 2;
    }

    cout << l << "\n";

    return 0;
}
