#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define MAX_N 100005

using namespace std;

ll costs[MAX_N];
ll memo[MAX_N];
int N;

ll solve(ll i, ll target) {
  if (target <= 0) {
    return 0;
  }

  if (i == N) {
    return target * 2 * costs[N - 1];
  }

  if (target == 1) {
    return memo[i];
  }

  if (target % 2 == 0) {
    return solve(i + 1, target / 2);
  } else {
    return min(costs[i] + solve(i + 1, target / 2),
               solve(i + 1, target / 2 + 1));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int Q;
  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    costs[i] = a;
  }

  for (int i = 1; i < N; i++) {
    costs[i] = min(costs[i], costs[i - 1] * 2);
  }

  memo[N - 1] = costs[N - 1];
  for (int i = N - 1; i >= 1; i--) {
    memo[i - 1] = min(costs[i - 1], memo[i]);
  }

  while (Q--) {
    ll x;
    cin >> x;
    cout << solve(0, x) << "\n";
  }

  return 0;
}
