#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c;
  cin >> n >> c;

  int f[100005];
  int p[100005];

  for (int i = 0; i < c; i++) {
    cin >> f[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  vector<set<int>> sats = vector<set<int>>(c);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;

      sats[--s].insert(p[i]);
    }
  }

  unordered_set<int> declined;

  for (int i = 0; i < n; i++) {
    unordered_set<int> invited;
    ll sum = 0;

    for (int j = 0; j < c; j++) {
      int sofar = 0;

      for (auto curr = sats[j].begin(); sofar < f[j] && curr != sats[j].end();
           curr++) {
        if (declined.find(*curr) != declined.end()) {
          continue;
        }

        if (invited.find(*curr) == invited.end()) {
          invited.insert(*curr);
          sum += *curr + 1;
          sofar++;
        }
      }
    }

    cout << sum << "\n";

    declined.insert(p[i]);
  }

  return 0;
}
