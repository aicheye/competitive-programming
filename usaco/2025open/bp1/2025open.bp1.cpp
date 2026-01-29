#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<unordered_set<int>> lose = vector<unordered_set<int>>(N);

  for (int i = 0; i < N; i++) {
    string chart;
    cin >> chart;
    for (int j = 0; j <= i; j++) {
      switch (chart[j]) {
      case 'W':
        lose[j].insert(i);
        break;
      case 'L':
        lose[i].insert(j);
        break;
      }
    }
  }

  while (M--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    int wins_both = 0;

    for (int winner : lose[l]) {
      if (lose[r].find(winner) != lose[r].end()) {
        wins_both++;
      }
    }

    int res = 0;
    while (wins_both--) {
      res += (N - 1 - wins_both) * 2 + 1;
    }
    cout << res << "\n";
  }

  return 0;
}
