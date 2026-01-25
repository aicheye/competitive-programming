#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string rle;
  cin >> rle;

  ll N;
  cin >> N;

  char c;
  c = rle.at(0);

  ll curr = 0;
  ll count = 0;

  vector<pair<ll, char>> begins;

  begins.push_back(pair(curr, c));

  for (int i = 1; i < rle.size(); i++) {
    char t = rle.at(i);
    if (!('0' <= t && t <= '9')) {
      begins.push_back(pair(curr, t));
      c = t;
      count = 0;
    } else {
      curr -= count;
      count *= 10;
      count += t - '0';
      curr += count;
    }
  }

  ll idx = N % curr;

  for (int i = 0; i < begins.size(); i++) {
    auto [a, b] = begins[i];
    if (a > idx) {
      cout << begins[i - 1].second << "\n";
      return 0;
    }
  }

  cout << c << "\n";
  return 0;
}
