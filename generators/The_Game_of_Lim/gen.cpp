// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long

int N;

int f(ll n, int m) {
    return ((n % m) + m) % m;
}

ll randll() {
    ll rll = 0;
    for (int i=0; i<4; i++)
        rll = (rll << (sizeof(int) * 8)) | rand();
    return rll;
}

int rint(int a, int b) {
    return f(randll(), b - a + 1) + a;
}

void bubbleSort(int arr[]) {
    bool sorted = false;
    int lo = 0;
    int hi = N - 1;
    while (!sorted) {
        sorted = true;

        for (int i = lo; i <= hi - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;

                cerr << arr[0];
                for (int j=1; j<N; j++) {
                    cerr << " " << arr[j];
                }
                cerr << "\n";
            }
        }

        hi--;

        for (int i = hi; i >= lo + 1; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                sorted = false;

                cerr << arr[0];
                for (int j=1; j<N; j++) {
                    cerr << " " << arr[j];
                }
                cerr << "\n";
            }
        }

        lo++;
    }
}

void gen(int T) {
    N = rint(1, 200);
    cout << N << "\n";

    int arr[N];

    if (T == 3) for (int i=0; i<N; i++) arr[i] = i;
    else if (T == 8) for (int i=0; i<N; i++) arr[i] = N - i;
    else for (int i=0; i<N; i++) {
        int a = rint(0, (int) 1e6);
        arr[i] = a;
    }

    cout << arr[0];
    for (int j=1; j<N; j++) {
        cout << " " << arr[j];
    }
    cout << "\n";

    bubbleSort(arr);
}


int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = atoi(argv[1]);
    unsigned int seed = T*13+555555;

    srand(seed);
    gen(T);

    return 0;
}
