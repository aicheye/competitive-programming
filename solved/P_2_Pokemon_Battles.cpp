#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, unordered_map<string, int>> eff;

    eff["FIRE"]["WATER"] = 2;
    eff["FIRE"]["FIRE"] = 1;
    eff["FIRE"]["GRASS"] = 0;

    eff["WATER"]["WATER"] = 1;
    eff["WATER"]["FIRE"] = 0;
    eff["WATER"]["GRASS"] = 2;

    eff["GRASS"]["WATER"] = 0;
    eff["GRASS"]["FIRE"] = 2;
    eff["GRASS"]["GRASS"] = 1;

    string E;
    int N;
    cin >> E >> N;

    int ans = 0;
    while (N--) {
        int x;
        string t;
        cin >> x >> t;

        if (eff[E][t] == 2) ans = max(x*2, ans);
        else if (eff[E][t] == 1) ans = max(x, ans);
        else ans = max(x/2, ans);
    }

    cout << ans << "\n";

    return 0;
}
