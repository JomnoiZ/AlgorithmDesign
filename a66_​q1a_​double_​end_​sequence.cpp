#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int a[300005];

int solve(int l, int r) {
    if (l == r) return a[l];

    int mid = (l + r) / 2;
    int res = max(solve(l, mid), solve(mid + 1, r));

    vector <int> mp(2000, -INF);
    int sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += a[i];
        mp[a[i] + 1000] = max(mp[a[i] + 1000], sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += a[i];
        if (mp[a[i] + 1000] != INF) res = max(res, mp[a[i] + 1000] + sum);
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << solve(1, n);
    return 0;
}
