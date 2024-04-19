#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int n, k, min_diff = INF;
int a[101], qs[101];

void solve(int i, int m, int s) {
    if (m == 0) {
        min_diff = min(min_diff, abs(s - k));
        return;
    }
    if (s + qs[n] - qs[n - m] - k >= min_diff) return;
    if (k - (s + qs[m]) >= min_diff) return;
    if (n - i < m) return;
    if (i == n) return;

    solve(i + 1, m - 1, s + a[i]);
    solve(i + 1, m, s);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater <int> ());
    for (int i = 0; i < n; i++) qs[i + 1] = qs[i] + a[i];

    solve(0, m, 0);

    cout << min_diff;
    return 0;
}