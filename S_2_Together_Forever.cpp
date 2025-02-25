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

    vector<stack<int>> idx;
    idx.resize(N+1);
    
    int A[(int) 1e6 + 2];
    for (int i=0; i<N; i++) cin >> A[i];

    int B[(int) 1e6 + 2];
    for (int i=0; i<N; i++) cin >> B[i];

    vector<pair<int, int>> swaps;

    for (int i=0; i<N; i++) {
        int a = A[i];
        int b = B[i];

        if (a != b) {
            idx[a].push(i);
            if (!idx[b].empty()) {
                swaps.push_back({ idx[b].top() + 1, i + 1 });
                if (B[idx[b].top()] != a) {
                    idx[a].pop();
                    idx[a].push(idx[b].top());
                }
                idx[b].pop();
            }
        }
    }

    bool op = true;
    while (op) {
        op = false;
        for (int i=1; i<=N; i++) {
            if (!idx[i].empty()) {
                int a = B[idx[i].top()];
                swaps.push_back({ idx[a].top() + 1, idx[i].top() + 1 });
                idx[i].pop();
                if (B[idx[a].top()] != i) idx[i].push(idx[a].top());
                idx[a].pop();
                op = true;
            }
        }
    }

    cout << swaps.size() << "\n";
    for (pair<int, int> swap : swaps) {
        cout << swap.first << " " << swap.second << "\n";
    }

    return 0;
}
