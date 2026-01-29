#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<int> cows = vector<int>(N, 0);

    int res = 0;
    int tall = -1;

    for (int i = 0; i < N; i++) {
      int h;
      cin >> h;
      if (++cows[--h] == 2) {
        res += 2;
        tall = max(h, tall);
      }
    }

    for (int i = tall + 1; i < N; i++) {
      if (cows[i] == 1) {
        res++;
        break;
      }
    }

    if (res % 2 == 0) {
      res--;
    }

    cout << res << "\n";
  }

  return 0;
}
