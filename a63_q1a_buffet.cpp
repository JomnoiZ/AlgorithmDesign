#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, K, m;
    cin >> n >> K >> m;

    vector <int> d(n + 1), qs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];

        qs[i] = qs[i - 1] + d[i] - m;
    }

    while (K--) {
        int p, w;
        cin >> p >> w;

        int l = p, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (qs[mid] - qs[p - 1] >= w) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}