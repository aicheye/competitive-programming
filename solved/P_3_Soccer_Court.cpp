#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll PSA[805][405] = {{0}};

vector<vector<int>> factors;

void fill() {
    factors.resize(160005);

    for (int i=1; i*i<160005; i++) {
        for (int j=i; j<160005; j+=i) {
            factors[j].push_back(i);
        }
    }
}

// sum from (x1, y1) to (x2, y2), inclusive
// AB - Ab - aB + ab
ll sum(int r1, int c1, int r2, int c2) {
    return PSA[r2+1][c2+1] - PSA[r1][c2+1] - PSA[r2+1][c1] + PSA[r1][c1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    fill();

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            ll curr;
            cin >> curr;
            PSA[i][j] = curr + PSA[i-1][j] + PSA[i][j-1] - PSA[i-1][j-1];
        }
    }
    
    for (int a=(M/2)*2*N; a>=2; a-=2) {
        for (int factor : factors[a/2]) {
            int w = factor * 2;
            int h = a / w;
            for (int i=0; i+h-1<N; i++) {
                for (int j=0; j+w-1<M; j++) {
                    if (sum(i, j, i+h-1, j+w/2-1) == sum(i, j+w/2, i+h-1, j+w-1)) {
                        cout << a << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "0\n";
    return 0;
}
