#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int c[55], qc[55];
bitset <55> p;

void solve(int i, int sum, bitset <55> s) {
    if (i == n) return void(ans = max(ans, sum));
    if (sum + qc[i] <= ans) return;
    
    if (i < k - 1) {
        s[i] = 1;
        if (i == 0 or (i > 0 and s[i - 1] == 0)) solve(i + 1, sum + c[i], s);
        s[i] = 0;
        solve(i + 1, sum, s);
    }
    else {
        if (i >= k) s >>= 1;
        s[k - 1] = 1;
        if (s[k - 2] == 0 and s != p) solve(i + 1, sum + c[i], s);
        s[k - 1] = 0;
        if (s != p) solve(i + 1, sum, s);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        p[i] = x;
    }

    qc[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; i--) qc[i] = qc[i + 1] + c[i];

    solve(0, 0, bitset <55> ());

    cout << ans;
    return 0;
}