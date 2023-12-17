#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;

int a[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        a[i] += a[i - 1];
    }

    while (m--) {
        int L;
        long long b;
        cin >> L >> b;

        L++;
        int l = L, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (a[mid] - a[L - 1] + (mid - L + 1) * k <= b) l = mid + 1, ans = a[mid] - a[L - 1];
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}