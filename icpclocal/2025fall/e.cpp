#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

bool solve() {
  int n, m;
  cin >> n >> m;

  if (n == 0 && m == 0) {
    return false;
  }

  priority_queue<int, vector<int>, greater<int>> lectures;
  priority_queue<int, vector<int>, greater<int>> rooms;

  while (n--) {
    int foo;
    cin >> foo;
    lectures.push(foo);
  }

  while (m--) {
    int bar;
    cin >> bar;
    rooms.push(bar);
  }

  int sum = 0;

  while (!lectures.empty()) {
    int next = lectures.top();
    lectures.pop();

    while (rooms.top() < next) {
      rooms.pop();
    }

    if (rooms.empty()) {
      cout << "Impossible\n";
      return true;
    }

    sum += rooms.top();
    rooms.pop();
  }

  cout << sum << "\n";
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool cont = true;

  do {
    cont = solve();
  } while (cont);

  return EXIT_SUCCESS;
} 
