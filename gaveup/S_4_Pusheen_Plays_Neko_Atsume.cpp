#include <bits/stdc++.h>
#include <cstddef>
#include <ios>

using namespace std;

int main(int argv, char **argc) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d, Q;

  cin >> a >> b >> c >> d >> Q;

  while (Q--) {
    int x;
    cin >> x;

    vector<int> f1 = vector<int>();
    vector<int> f2 = vector<int>();

    f1.push_back(x);
    f2.push_back(x);

    int acc = 0;

    while (!f1.empty() && !f2.empty()) {
      for (int i = f1.size() - 1; i >= 0; i--) {
        int res = f1[i] / a - b;
        f1.pop_back();
        if (res > 0) {
          f1.push_back(res);
          f2.push_back(res);
        } else {
          acc++;
        }
      }
      for (int i = f2.size() - 1; i >= 0; i--) {
        int res = f2[i] / c - d;
        f2.pop_back();
        if (res > 0) {
          f1.push_back(res);
          f2.push_back(res);
        } else {
          acc++;
        }
      }
    }

    cout << acc << "\n";
  }

  return EXIT_SUCCESS;
}
