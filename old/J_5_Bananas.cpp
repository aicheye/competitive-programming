#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string q;
    cin >> q;
    while (q != "X") {
        vector<char> monkeys;
        for (int i=0; i<q.size(); i++) monkeys.push_back(q.at(i));

        bool op = true;
        while (op && monkeys.size() > 1) {
            op = false;
            for (int i=0; i<monkeys.size() - 2 && !op; i++) {
                if (monkeys[i] == 'A' && monkeys[i+1] == 'N' && monkeys[i+2] == 'A') {
                    monkeys.erase(monkeys.begin() + i+1);
                    monkeys.erase(monkeys.begin() + i+1);
                    op = true;
                }
                else if (monkeys[i] == 'B' && monkeys[i+1] == 'A' && monkeys[i+2] == 'S') {
                    monkeys.erase(monkeys.begin() + i);
                    monkeys.erase(monkeys.begin() + i+1);
                    op = true;
                }
            }
        }

        if (monkeys.size() == 1 && monkeys[0] == 'A') cout << "YES\n";
        else cout << "NO\n";

        cin >> q;
    }
    
    return 0;
}
