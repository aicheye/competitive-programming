#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, k;
  cin >> T >> k;

  while (T--) {
    int N;
    cin >> N;

    string S;
    cin >> S;

    cout << "YES\n"; // always possible

    if (!k) {
      continue;
    }

    bool flip = false;

    string ans(N, 'O');

    for (int i = N - 1; i >= 0; i--) {
      switch (S[i]) {
      case 'O':
        ans[i] = !flip ? 'O' : 'M';
        break;
      default:
        ans[i] = !flip ? 'M' : 'O';
        break;
      }

      if (ans[i] == 'O') {
        flip = !flip; 
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
