#include <bits/stdc++.h>
using namespace std;

int n, m, k, w, sumh, ans;
int p[10], h[10], t[10];

void solve(int i, int cnt) {
    if (i == k) {
        ans = min(ans, sumh - cnt);
        return;
    }

    for (int j = 0; j < m; j++) {
        if (abs(t[i] - p[j]) <= w and h[j] > 0) {
            h[j]--;
            solve(i + 1, cnt + 1);
            h[j]++;
        }
        else solve(i + 1, cnt);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> k >> w;

    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        cin >> h[i];

        sumh += h[i];
    }
    for (int i = 0; i < k; i++) cin >> t[i];

    ans = sumh;
    solve(0, 0);
    cout << ans;
    return 0;
}