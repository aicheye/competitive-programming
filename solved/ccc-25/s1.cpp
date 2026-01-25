#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B, X, Y;
  cin >> A >> B >> X >> Y;

  int op1 = (A + X) * 2 + max(B, Y) * 2;
  int op2 = (B + Y) * 2 + max(A, X) * 2;

  cout << min(op1, op2) << "\n";

  return 0;
}
