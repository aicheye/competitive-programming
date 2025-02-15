#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, K;
    ll M;
    cin >> R >> C >> K >> M;

    ll dp[202][102][102][2] = {{{{0}}}};

    dp[0][0][0][0] = 1;
    dp[0][1][0][0] = 1;
    dp[0][0][1][1] = 1;

    for (int t=0; t<=K; t++) {
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                if (!(t==0 && r==0 && c==0)) {
                    int r2, c2;
                    r2 = r + 1;
                    c2 = c + 0;
                    if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
                        dp[t+1][r2][c2][0] += dp[t][r][c][1];
                        dp[t+1][r2][c2][0] %= M;
                        dp[t][r2][c2][0] += dp[t][r][c][0];
                        dp[t][r2][c2][0] %= M;
                    }
                    r2 = r + 0;
                    c2 = c + 1;
                    if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
                        dp[t+1][r2][c2][1] += dp[t][r][c][0];
                        dp[t+1][r2][c2][1] %= M;
                        dp[t][r2][c2][1] += dp[t][r][c][1];
                        dp[t][r2][c2][1] %= M;
                    }
                }
            }
        }
    }
    
    ll ans = (dp[K][R-1][C-1][0] + dp[K][R-1][C-1][1]) % M; 
    cout << ans << "\n";
    return 0;
}
