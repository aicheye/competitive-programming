#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string conc(string q) {
    if (q.empty()) return "";

    string ans;
    char last = q.at(0);
    int r = 1;

    for (int i=1; i<q.length(); i++) {
        if (q.at(i) == last) r++;
        else {
            ans += to_string(r);
            ans += last;
            last = q.at(i);
            r = 1;
        }
    }

    ans += to_string(r);
    ans += last;
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string q;
    cin >> q;

    while (n--) q = conc(q);

    cout << q << "\n";

    return 0;
}