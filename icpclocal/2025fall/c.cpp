#include <bits/stdc++.h>

#pragma GCC opimize("Ofast,unroll-loops")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  vector<int> r;
  int R = 0;
  for (int i = 0; i < k; i++) {
    int foo;
    cin >> foo;
    r.push_back(foo);
    R += foo;
  }

  vector<int> c;
  int C = 0;
  for (int i = 0; i < k; i++) {
    int bar;
    cin >> bar;
    c.push_back(bar);
    C += bar;
  }

  int m[R][C];

  int rMin = C / 2 + 1;
  int cMin = R / 2 + 1;

  vector<int> rCount = vector<int>(R, 0);
  vector<int> cCount = vector<int>(C, 0);

  int rTarget[R];
  int curr = 0;
  for (int i = 0; i < r.size(); i++) {
    for (int next = curr + r[i]; curr < next; curr++) {
      rTarget[curr] = i + 1;
    }
  }

  int cTarget[C];
  curr = 0;
  for (int i = 0; i < c.size(); i++) {
    for (int next = curr + c[i]; curr < next; curr++) {
      cTarget[curr] = i + 1;
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (rTarget[i] == cTarget[j]) {
        m[i][j] = rTarget[i];
        rCount[i]++;
        cCount[j]++;
      } else {
        m[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (m[i][j] > 0) {
        continue;
      }

      if (rTarget[i] < rMin && cTarget[j] >= cMin) {
        m[i][j] = rTarget[i];
        rCount[i]++;
      } else if (cTarget[j] < cMin && rTarget[i] >= rMin) {
        m[i][j] = cTarget[j];
        cCount[i]++;
      } else if (rTarget[i] < rMin && cTarget[j] < cMin) {
        for (int i2 = i; i2 < R && rTarget[i2] == rTarget[i]; i2++) {
          for (int j2 = j; j2 < C && cTarget[j2] == cTarget[j]; j2++) {
            if (rTarget[i] >= rMin) {
              m[i2][j2] = cTarget[j];
              cCount[j]++;
            } else if (cTarget[j] >= cMin) {
              m[i2][j2] = rTarget[i];
              rCount[i]++;
            } else if ((i2 + j2) % 2 == 0) {
              m[i2][j2] = rTarget[i];
              rCount[i2]++;
            } else {
              m[i2][j2] = cTarget[j];
              cCount[j2]++;
            }
          }
        }
      } else {
        m[i][j] = rTarget[i];
        rCount[i]++;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (rCount[i] >= rMin && cCount[j] < cMin) {
        m[i][j] = cTarget[j];
        cCount[j]++;
      } else if (cCount[j] >= cMin && rCount[i] < rMin) {
        m[i][j] = rTarget[i];
        rCount[i]++;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    if (rCount[i] < rMin) {
      cout << "NO\n";
      return EXIT_SUCCESS;
    }
  }

  for (int i = 0; i < C; i++) {
    if (cCount[i] < cMin) {
      cout << "NO\n";
      return EXIT_SUCCESS;
    }
  }

  cout << "YES\n";

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }

  return EXIT_SUCCESS;
} 
