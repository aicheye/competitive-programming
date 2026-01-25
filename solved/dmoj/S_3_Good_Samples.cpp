#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<int> notes;
    set<int> can;
    for (int i=2; i<=M; i++) can.insert(i);

    notes.push_back(1);
    int l = 1;
    
    ll goods = N;
    if (K < goods || (M == 1 && K != N)) {
        cout << "-1\n";
        return 0;
    }

    while (notes.size() < N) {
        int end = notes.size() - 1;

        if (goods == K) {
            cout << notes[0];
            for (int i=1; i<N; i++) {
                if (i <= end) cout << " " << notes[i];
                else cout << " " << notes[end];
            }
            cout << "\n";
            return 0;
        }

        if (goods + l <= K) {
            if (l == M) {
                notes.push_back(notes[end-l+1]);
                goods += (l-1);
            }
            else {
                notes.push_back(*can.begin());
                can.erase(can.begin());
                goods += l;
                l++;
            }
            continue;
        }
        
        int add = K - goods;
        notes.push_back(notes[end-add]);
        goods += add;
        l = add + 1;
        can.clear();
        for (int i=1; i<=M; i++) can.insert(i);
        for (int i=end-l+2; i<=end+1; i++)
            can.erase(notes[i]);
    }

    if (goods == K) {
        cout << notes[0];
        for (int i=1; i<N; i++) cout << " " << notes[i];
        cout << "\n";
    }

    else cout << "-1\n";

    return 0;
}
