#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <int> a(N);
    for (auto &x : a) cin >> x;

    while (M--) {
        int x;
        cin >> x;

        int l = 0, r = N - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (a[mid] <= x) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}