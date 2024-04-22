#include <bits/stdc++.h>
using namespace std;

int n, ans;
int b[50], qb[50];
bitset <50> f[50];

void solve(int i, int sum, bitset <50> s, bitset <50> chosen) {
    if (i == n) return void(ans = max(ans, sum));
    if (sum + qb[i] <= ans) return;

    chosen[i] = 1;
    if ((s & f[i] & chosen) == chosen) solve(i + 1, sum + b[i], s & f[i], chosen);
    chosen[i] = 0;

    solve(i + 1, sum, s, chosen);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            f[i][j] = x;
        }
    }

    qb[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) qb[i] = qb[i + 1] + b[i];

    bitset <50> tmp;
    for (int i = 0; i < n; i++) tmp[i] = 1;

    solve(0, 0, bitset <50> ().set(), bitset <50> ());

    cout << ans;
    return 0;
}