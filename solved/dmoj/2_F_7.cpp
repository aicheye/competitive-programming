#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> points;
    points.resize(N);
    for (int i=0; i<N; i++) cin >> points[i];

    sort(points.begin(), points.end(), greater<int>());

    int top = 0;
    for (int i=0; i<N; i++) top = max(points[i] + 1 + i, top);
    for (int i=1; i<N; i++) if (points[i] + N < top) {
        cout << i << "\n";
        return 0;
    }

    cout << N << "\n";
    return 0;
}
