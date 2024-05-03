#include <bits/stdc++.h>
using namespace std;

const int MOD = 16777216;

int ans = MOD;

void solve(const int &c, const int &x) {
    if (c >= ans) return;
    if (x == 0) return void(ans = c);

    solve(c + 1, 2 * x % MOD);
    solve(c + 1, (x + 1) % MOD);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int x;
    cin >> x;

    solve(0, x);

    cout  << ans;
    return 0;
}