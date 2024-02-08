#include <bits/stdc++.h>
using namespace std;

int solve(int n, int l, int r, int ql, int qr) {
    if (r < ql or qr < l) return 0;
    if (n == 1) return 1;

    int mid = (l + r) / 2;
    return solve(n / 2, l, mid - 1, ql, qr) + solve(n / 2, mid + 1, r, ql, qr) + (ql <= mid and mid <= qr and n % 2 == 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, l, r;
    cin >> n >> l >> r;

    int s = 0;
    while (s < n) s = s * 2 + 1;
    
    cout << solve(n, 1, s, l, r);
    return 0;
}