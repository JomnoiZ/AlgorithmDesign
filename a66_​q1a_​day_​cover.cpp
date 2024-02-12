#include <bits/stdc++.h>
using namespace std;

bitset <1000> a[20];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        while (k--) {
            int d;
            cin >> d;

            d--;
            a[i][d] = 1;
        }
    }

    int ans = m;
    for (int mask = 0; mask < (1<<m); mask++) {
        bitset <1000> chk;
        for (int i = 0; i < m; i++) {
            if (mask & (1<<i)) chk = chk | a[i];
        }
        if (chk.count() == n) ans = min(ans, __builtin_popcount(mask));
    }
    cout << ans;
    return 0;
}
