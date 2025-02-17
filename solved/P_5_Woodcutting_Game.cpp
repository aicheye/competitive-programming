#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool win[5][302][5][302];
bool vis[5][302][5][302] = {0};

vector<int> desym(vector<int> s) {
    //if (s[0] <= 2 && s[1] <= 2 && s[1] > s[0]) swap(s[0], s[1]);
    //if (s[2] <= 2 && s[3] <= 2 && s[3] > s[2]) swap(s[2], s[3]);
    if (s[2] > s[0]) return { s[2], s[3], s[0], s[1] };
    else if (s[2] == s[0] && s[3] > s[1]) return { s[2], s[3], s[0], s[1] };
    return s;
}

vector<vector<int>> op1(pair<int, int> r1, pair<int, int> r2) {
    vector<vector<int>> states, states2;
    vector<int> state;
    pair<int, int> r3, r4;

    if (r1.first == 2) {
        r3.first = 1;
        r3.second = r1.second;
        r4.first = 1;
        r4.second = r1.second;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    if (r2.first == 2) {
        r3.first = 1;
        r3.second = r2.second;
        r4.first = 1;
        r4.second = r2.second;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    for (int i=1; i<r1.second; i++) {
        r3.first = r1.first;
        r3.second = i;
        r4.first = r1.first;
        r4.second = r1.second - i;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    for (int i=1; i<r2.second; i++) {
        r3.first = r2.first;
        r3.second = i;
        r4.first = r2.first;
        r4.second = r2.second - i;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    for (vector<int> s : states2) states.push_back(s);

    return states;
}

vector<vector<int>> op2(pair<int, int> r1, pair<int, int> r2) {
    vector<vector<int>> states, states2;
    vector<int> state;
    pair<int, int> r3, r4;

    if (r1.first == 2) {
        r3.first = 1;
        r3.second = r1.second;
        r4.first = r2.first;
        r4.second = r2.second;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    if (r2.first == 2) {
        r3.first = 1;
        r3.second = r2.second;
        r4.first = r1.first;
        r4.second = r1.second;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    for (int i=1; i<=10 && i<r1.second; i++) {
        r3.first = r1.first;
        r3.second = r1.second - i;
        r4.first = r2.first;
        r4.second = r2.second;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    for (int i=1; i<=10 && i<r2.second; i++) {
        r3.first = r2.first;
        r3.second = r2.second - i;
        r4.first = r1.first;
        r4.second = r1.second;
        states.push_back({ r3.first, r3.second, r4.first, r4.second });
    }

    return states;
}

set<vector<int>> next(pair<int, int> r1, pair<int, int> r2) {
    vector<vector<int>> s1, s2;
    set<vector<int>> states;

    s1 = op1(r1, r2);
    s2 = op2(r1, r2);

    for (vector<int> s : s1) {
        s = desym(s);
        if (s[0] >= 1 && s[1] >= 1 && s[2] >= 1 && s[3] >= 1) {
            states.insert(s);
            if (vis[s[0]][s[1]][s[2]][s[3]] && !win[s[0]][s[1]][s[2]][s[3]]) return states;
        }
    }

    for (vector<int> s : s2) {
        s = desym(s);
        if (s[0] >= 1 && s[1] >= 1 && s[2] >= 1 && s[3] >= 1) {
            states.insert(s);
            if (vis[s[0]][s[1]][s[2]][s[3]] && !win[s[0]][s[1]][s[2]][s[3]]) return states;
        }
    }

    return states;
}

bool search(pair<int, int> r1, pair<int, int> r2) {
    set<vector<int>> states = next(r1, r2);
    vis[r1.first][r1.second][r2.first][r2.second] = true;
    bool &currW = win[r1.first][r1.second][r2.first][r2.second];
    //cout << r1.first << " " << r1.second << " " << r2.first << " " << r2.second << " ";

    for (vector<int> s : states) {
        if (vis[s[0]][s[1]][s[2]][s[3]] &&
            !win[s[0]][s[1]][s[2]][s[3]]) {
                return currW = true;
            }
        else if (!vis[s[0]][s[1]][s[2]][s[3]]) {
            if (!search(pair(s[0], s[1]), pair(s[2], s[3]))) {
                return currW = true;
            }
        }
    }

    return currW = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    win[1][1][1][1] = false;
    vis[1][1][1][1] = true;

    pair<int, int> r1, r2;
    cin >> r1.first >> r1.second >> r2.first >> r2.second;

    cout << (search(r1, r2) ? "W\n" : "L\n");

    return 0;
}
