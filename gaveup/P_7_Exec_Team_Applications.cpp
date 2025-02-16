#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // dp[m][a/b]: best way to select a group of m applicants
    ll dp[(int) 1e6 + 2][2];

    for (int i=0; i<N; i++) {
        dp[i][0] = LLONG_MAX;
        dp[i][1] = LLONG_MIN;
    }

    vector<pair<ll, ll>> applicants;

    for (int i=0; i<N; i++) {
        ll A, B;
        cin >> A >> B;
        applicants.push_back(pair(A, B));
    }

    for (int i=0; i<=M; i++) {
        int sel = 0;
        for (int j=0; j<applicants.size(); j++) {
            ll qual = min(dp[i][0], applicants[j].first) - max(dp[i][1], applicants[j].second);
            if (qual >= dp[i+1][0] - dp[i+1][1]) {
                dp[i+1][0] = min(dp[i][0], applicants[j].first);
                dp[i+1][1] = max(dp[i][1], applicants[j].second);
                sel = j;
            }
        }
        //cout << applicants[sel].first << " " << applicants[sel].second << "\n";
        applicants.erase(applicants.begin() + sel);
    }
    //for (int i=0; i<=M; i++) cout << dp[i][0] << " " << dp[i][1] << "\n";
    cout << dp[M][0] - dp[M][1] << "\n";

    return 0;
}
