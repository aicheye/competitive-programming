#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;
    C *= 2;

    vector<bool> rB4Empty (R, false);
    vector<int> rCount (R, C);
    vector<bool> cB4Empty (C, 0);

    rB4Empty[0] = true;
    cB4Empty[C/2-1] = true;
    cB4Empty[C/2] = true;

    for (int i=0; i<R*C; i++) {
        int s;
        cin >> s;
        s--;

        if (rB4Empty[s/C] && cB4Empty[s%C]) {
            if (--rCount[s/C] == 0 && s/C + 1 < R) {
                rB4Empty[s/C+1] = true;
                for (int j=0; j<C; j++) cB4Empty[j] = false; 
                cB4Empty[C/2-1] = true;
                cB4Empty[C/2] = true;
            }
            if (0 < s%C && s%C <= C/2 - 1) cB4Empty[s%C-1] = true;
            else if (s%C + 1 < C) cB4Empty[s%C+1] = true;
        }
        else {
            cout << "no\n";
            return 0;
        }
    }

    cout << "yes\n";
    return 0;
}
