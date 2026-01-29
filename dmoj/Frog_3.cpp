// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define ld long double

//     (hj-hi)^2 + C
//   = -2hihj + hi^2 + (hj^2 + C)

// m = -2hi
// b = hi^2

struct Line {
    ll slope, yint;

    Line(ll slope, ll yint) : slope(slope), yint(yint) {}

    Line() : slope((long long) 0), yint((long long) LLONG_MAX) {}

    ll eval(ll x) {
        return slope * x + yint;
    }

    ld intersect(Line other) {
        return ((ld) other.yint - yint) / (slope - other.slope);
    }
};

// true if b is unnecessary between a and c
bool bad(Line a, Line b, Line c) {
    return a.intersect(b) >= b.intersect(c);
}

// li chao tree
Line tree[(int) (2 * 1e5) + 5];

ll query(ll l, ll r, ll x, int idx=1) {
    if (l == r) {
        return tree[idx].eval(x);
    }

    ll mid = (l + r) / 2;
    int leftChild = idx * 2;
    int rightChild = idx * 2+1;
    if (x < mid) {
        return min(tree[idx].eval(x), query(l, mid, x, leftChild));
    } else {
        return min(tree[idx].eval(x), query(mid + 1, r, x, rightChild));
    }
}

void insert(ll l, ll r, Line in, int idx=1) {
    if (l == r) {
        if (in.eval(l) < tree[idx].eval(l)) {
            tree[idx] = in;
        }
    }

    ll mid = (l + r) / 2;
    ll leftChild = idx * 2;
    ll rightChild = idx * 2 + 1;

    if (tree[idx].eval(mid) > in.eval(mid)) {
        swap(tree[idx], in);
        insert(l, mid, in, leftChild);
    } else {
        insert(mid + 1, r, in, rightChild);
    }
}

int main() {
    ll N, C, Q;
    cin >> N >> C >> Q;

    ll dp[N];
    ll h[N];

    for (int i=0; i<N; i++) {
        cin >> h[i];
    }
    
    // base case
    dp[0] = 0;
    insert(1, N, Line(-2 * h[0], h[0] * h[0] + dp[0]));

    for (int i=1; i<N; i++) {
        dp[i] = query(1, N, h[i]) + h[i]*h[i] + C;

        // after querying, we can insert the new line
        insert(1, N, Line(-2 * h[i], h[i] * h[i] + dp[i]));
    }

    while (Q--) {
        ll q;
        cin >> q;

        cout << dp[--q] << "\n";
    }

    return 0;
}
