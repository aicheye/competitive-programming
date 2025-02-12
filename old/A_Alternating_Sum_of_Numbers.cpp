#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int sum = 0;
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            if (j % 2 == 0) {
                sum += a;
            }
            else {
                sum -= a;
            }
        }
        cout << sum << endl;
    }
}
