#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int PSA[402];

// get the sum from l to r (inclusive)
int sum(int l, int r) {
    return PSA[r] - PSA[l-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    PSA[0] = 0;

    int ans = 0;
    for (int i=0; i<N; i++) {
        cin >> PSA[i];
        ans = max(ans, PSA[i]);
    }

    for (int i=1; i<=N; i++) PSA[i] += PSA[i-1];

    bool mergeable[402][402] = {{0}};
    for (int i=0; i<N; i++) mergeable[i][i] = true;

    for (int s=2; s<=N; s++) {
        for (int l=0; l+s-1<N; l++) {
            // two
            for (int r=l+1; r-l<s; r++) {
                if (mergeable[l][r-1] && mergeable[r][l+s-1]) {
                    if (sum(l, r-1) == sum(r, l+s-1)) {
                        //cout << l << " " << r << "\n";
                        mergeable[l][l+s-1] = true;
                        ans = max(ans, sum(l, l+s-1));
                    }
                }
            }
            // three
            for (int m=l+1; m-l<s-1; m++) {
                for (int r=m+1; r-l<s; r++) {
                    if (mergeable[l][m-1] && mergeable[m][r-1] && mergeable[r][l+s-1]) {
                        if (sum(l, m-1) == sum(r, l+s-1)) {
                            //cout << l << " " << m << " " << r << "\n";
                            mergeable[l][l+s-1] = true;
                            ans = max(ans, sum(l, l+s-1));
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
