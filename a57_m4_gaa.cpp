#include <bits/stdc++.h>
using namespace std;

char solve(int k, int n, int x) {
    if (k == 0) {
        if (x == 1) return 'g';
        return 'a';
    }

    int m = (n - k) / 2;
    if (x <= m) return solve(k - 1, m, x);
    if (x - m <= k) {
        if (x - m == 1) return 'g';
        return 'a';
    }
    return solve(k - 1, m, x - m - k);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    int s = 3, k = 3;
    while (s < N) {
        k++;
        s = s * 2 + k;
    }
    cout << solve(k, s, N);
    return 0;
}
