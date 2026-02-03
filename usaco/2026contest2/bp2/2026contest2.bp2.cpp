#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define MAX_N 20

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;

  int dp[1 << (MAX_N + 1)] = {0};

  while (K--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    z--;

    dp[1 << x]++;
    dp[(1 << x) | (1 << y)]--;
    dp[(1 << x) | (1 << z)]--;
    dp[(1 << x) | (1 << y) | (1 << z)]++;
  }

  for (int i = 0; i < N; i++) {
    for (int mask = 0; mask < (1 << N); mask++) {
      if (mask & (1 << i)) {
        dp[mask] += dp[mask ^ (1 << i)];
      }
    }
  }

  int max = -1;
  int num = 0;

  for (int mask = 0; mask < (1 << N); mask++) {
    if (dp[mask] > max) {
      max = dp[mask];
      num = 1;
    } else if (dp[mask] == max) {
      num++;
    }
  }

  cout << max << " " << num << "\n";

  return 0;
}
