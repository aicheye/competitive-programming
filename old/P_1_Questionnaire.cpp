#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ok[102] = {0};
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            ok[j] += a;
        }
    }

    priority_queue<pair<int, int>> order;
    for (int i=0; i<m; i++) {
        order.push(pair(ok[i], -i));
    }

    cout << -order.top().second + 1;
    order.pop();
    
    for (int i=1; i<m; i++) {
        cout << " " << -order.top().second + 1;
        order.pop();
    }

    cout << "\n";

    return 0;
}
