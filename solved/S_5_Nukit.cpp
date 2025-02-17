#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed char memo[50][50][50][50];

bool win(int A, int B, int C, int D) {
    if (memo[A][B][C][D] == 1) return true;
    if (!memo[A][B][C][D]) return false;
    if ((A<2 || B<1 || D<2) && (A<1 || B<1 || C<1 || D<1) && (C<2 || D<1) && (B<3) && (A<1 || D<1))
        return (memo[A][B][C][D] = 0);
    if (A>=2 && B>=1 && D>=2)
        if (!win(A-2, B-1, C, D-2)) return (memo[A][B][C][D] = 1);
    if (A>=1 && B>=1 && C>=1 && D>=1)
        if (!win(A-1, B-1, C-1, D-1)) return (memo[A][B][C][D] = 1);
    if (C>=2 && D>=1)
        if (!win(A, B, C-2, D-1)) return (memo[A][B][C][D] = 1);
    if (B>=3)
        if (!win(A, B-3, C, D)) return (memo[A][B][C][D] = 1);
    if (A>=1 && D>=1)
        if (!win(A-1, B, C, D-1)) return (memo[A][B][C][D] = 1);
    return (memo[A][B][C][D] = 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int a=0; a<50; a++) for (int b=0; b<50; b++) for (int c=0; c<50; c++) for (int d=0; d<50; d++)
        memo[a][b][c][d] = -1;
    
    int N;
    cin >> N;

    while (N--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << (win(A, B, C, D) ? "Patrick\n" : "Roland\n");
    }

    return 0;
}
