#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    cin >> X >> Y >> Z;

    int N;
    cin >> N;

    double ans = INT_MAX;

    while (N--) {
        double x, y, z;
        cin >> x >> y >> z;

        double dx, dy, dz;
        dx = abs(x - X);
        dy = abs(y - Y);
        dz = abs(z - Z);

        double t = 0;

        if (z <= Z) {
            t += dz;
            t += sqrt(dx*dx + dy*dy)/2;
        }

        else {
            t += dz/4;
            if (t*3 < sqrt(dx*dx + dy*dy)) {
                double t2 = (sqrt(dx*dx + dy*dy)-t*3)/2;
                t += t2;
            }
        }

        ans = min(ans, t);
    }

    cout << ans << "\n";
    return 0;
}
