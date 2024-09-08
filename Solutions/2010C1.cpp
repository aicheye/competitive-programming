#include <iostream>
using namespace std;

int main() {
    string t;
    cin >> t;

    for (int i=1; i<t.length()/2; i++) {
        string h1 = t.substr(0, t.length() / 2 + i);
        string h2 = t.substr(t.length() / 2 - i + (t.length() % 2 == 1), t.length() / 2 + i);

        if (h1 == h2) {
            cout << "YES" << endl << h1 << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
