#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int X;

bool cons(int a, int b) {
    if (a > b && a - b == 1 && b % 2 == 0) return true;
    else if (b > a && b - a == 1 && a % 2 == 0) return true;
    return false;
}

bool same(int a, int b) {
    return a < X*2 && b < X*2 && cons(a, b);
}

bool diff(int a, int b) {
    return a >= X*2 && b >= X*2 && cons(a, b);
}

int comp(vector<int> A, vector<int> B) {
    for (int a : A) for (int b : B) {
        if (same(a, b)) return -1;
        else if (diff(a, b)) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, vector<int>> names;
    //vector<pair<int, int>> same;
    //vector<pair<int, int>> diff;

    string n1, n2;

    cin >> X;
    for (int i=0; i<X; i++) {
        cin >> n1 >> n2;
        names[n1].push_back(i*2);
        names[n2].push_back(i*2 + 1);
        //same.push_back(pair(i*2, i*2+1));
    }

    int Y;
    cin >> Y;
    for (int i=0; i<Y; i++) {
        cin >> n1 >> n2;
        names[n1].push_back(X*2 + i*2);
        names[n2].push_back(X*2 + i*2 + 1);
        //diff.push_back(pair(X*2 + i*2, X*2 + i*2 + 1));
    }

    int ans = X;

    int G;
    cin >> G;
    while (G--) {
        vector<string> n;
        n.resize(3);
        cin >> n[0] >> n[1] >> n[2];

        vector<vector<int>> indices;

        if (names.find(n[0]) != names.end()) indices.push_back(names[n[0]]);
        if (names.find(n[1]) != names.end()) indices.push_back(names[n[1]]);
        if (names.find(n[2]) != names.end()) indices.push_back(names[n[2]]);

        if (indices.size() == 2) ans += comp(indices[0], indices[1]);
        else if (indices.size() == 3) {
            ans += comp(indices[0], indices[1]);
            ans += comp(indices[1], indices[2]);
            ans += comp(indices[0], indices[2]);
        }
    }
    
    cout << ans << "\n";

    return 0;
}
