//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<set<vector<int>, greater<vector<int>>>> ans;

void add(vector<int> vec, int no);

void sub(vector<int> vec, int no) {
    for (int i=1; i<vec.size()-1; i++) {
        if (vec[i] > vec[i-1] && i != no) {
            vec[i]--;
            add(vec, i);
        }
    }
    if (--vec[vec.size()-1] == 0) vec.erase(vec.end()-1);
    add(vec, -1);
}

void add(vector<int> vec, int no) {
    vec[0]++;
    if (ans[vec.size()-1].find(vec) == ans[vec.size()-1].end()) {
        ans[vec.size()-1].insert(vec);
        if (vec.size() - 1 > 0) sub(vec, 0);
    }
    vec[0]--;
    for (int i=0; i<vec.size()-1; i++) {
        if (vec[i] > vec[i+1] && i+1 != no) {
            vec[i+1]++;
            if (ans[vec.size()-1].find(vec) == ans[vec.size()-1].end()) {
                ans[vec.size()-1].insert(vec);
                sub(vec, i);
            }
            vec[i+1]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    vector<int> stacks;
    stacks.resize(n);
    for (int i=0; i<n; i++) stacks[i] = 1;

    ans.resize(n);

    ans[n-1].insert(stacks);
    sub(stacks, -1);

    for (int i=0; i<n; i++) {
        for (vector<int> s : ans[i]) {
            cout << s[0];
            for (int k=1; k<s.size(); k++) cout << " " << s[k];
            cout << "\n";
        }
    }

    return 0;
}
