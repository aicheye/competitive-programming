#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int parents[3005][3];

void make_set(int a) {
    parents[a][0] = a;
    parents[a][1] = a;
}

int find_set(int a, int h) {
    if (parents[a][h] == a) return a;
    else return parents[a][h] = find_set(parents[a][h], h);
}

int union_set(int a, int b, int h) {
    a = find_set(a, h);
    b = find_set(b, h);
    if (a != b) parents[b][h] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i=0; i<N; i++) make_set(i);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int e;
            cin >> e;
            if (e == 1) union_set(i, j, 0);
            else if (e == 2) union_set(i, j, 1);
        }
    }

    int comp[2] = {0};

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (find_set(i, 0) != find_set(j, 0) && ++comp[0] > 1) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            if (find_set(i, 1) != find_set(j, 1) && ++comp[1] > 1) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    cout << "POSSIBLE\n";
    return 0;
}
