#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, D;
    cin >> N >> D;

    vector <int> s(N + 1);
    for (int i = 1; i <= N; i++) cin >> s[i];

    int l = 0, r = INF, ans = 0, d = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        int cnt = 1;
        int st = 0;
        for (int i = 1; i <= N; i++) {
            if (s[i] - s[i - 1] > mid) {
                cnt = INF;
                break;
            }
            if (s[i] - st > mid) {
                st = s[i - 1];
                cnt++;
            }
        }

        if (cnt <= D) r = mid - 1, ans = mid, d = cnt;
        else l = mid + 1;
    }
    cout << ans << ' ' << d;
    return 0;
}