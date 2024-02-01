#include <bits/stdc++.h>
using namespace std;

int u, v, w, p;

int solve(long long n, long long r, long long c) {
    if (n == 2) {
        if (r == 1 and c == 1) return u;
        if (r == 1 and c == 2) return v;
        if (r == 2 and c == 1) return w;
        return p;
    }

    long long m = n / 2;
    if (r <= m and c <= m) return solve(m, r, c);
    if (r <= m and c > m) return solve(m, c - m, r);
    if (r > m and c <= m) return -solve(m, r - m, c);
    return -solve(m, c - m, r - m);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m >> u >> v >> w >> p;

    n = min(n + 1, 60);
    while (m--) {
        long long r, c;
        cin >> r >> c;

        cout << solve(1ll<<n, r, c) << '\n';
    }
    return 0;
}