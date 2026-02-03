#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, c;
  cin >> t >> c;

  while (t--) {
    int n;
    cin >> n;

    vector<bool> lefts = vector<bool>(n);
    vector<bool> rights = vector<bool>(n);
    vector<bool> johns = vector<bool>(n);

    string l, r;
    cin >> l >> r;

    for (int i=0; i<n; i++) {
      lefts[i] = l[i] == 'J';
      rights[i] = r[i] == 'J';
    }
  }

  return 0;
}
