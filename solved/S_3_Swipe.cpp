#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int A[(int) 3e5 + 2];
    for (int i=0; i<N; i++) cin >> A[i];

    int B[(int) 3e5 + 2];
    int Ai = 0;
    for (int i=0; i<N; i++) {
        cin >> B[i];
        if (i == 0 || B[i] != B[i-1]) {
            while (Ai < N && A[Ai] != B[i]) Ai++;
        }
    }

    if (Ai == N) {
        cout << "NO";
        return 0;
    }

    // r, l (increasing r)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lefts;
    // l, r (decreasing l)
    priority_queue<pair<int, int>> rights;

    cout << "YES";
    for (int i=0; i<N; i++) {
        int l = 1;

        // test right first
        while (i+l < N && A[i] == B[i+l]) l++;
        // left
        if (l == 1) {
            while (i-l >= 0 && A[i] == B[i-l]) l++;
            lefts.push(pair(i, i-l));
        }
        else rights.push(pair(i, i+l));

        
    }

    return 0;
}
