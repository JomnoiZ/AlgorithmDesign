#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int n, k, ans = INF;
bitset <1024> b[80];
vector <int> idx;
int P[80];

void solve(int i, int tp, bitset <1024> mp) {
    if (tp >= ans) return;
    if (mp.count() == n) return void(ans = tp);
    if (i == k) return;

    solve(i + 1, tp + P[idx[i]], mp | b[idx[i]]);
    solve(i + 1, tp, mp);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int m;
        cin >> P[i] >> m;

        idx.push_back(i);
        while (m--) {
            int s;
            cin >> s;

            b[i][s - 1] = 1;
        }
    }

    sort(idx.begin(), idx.end(), [&](const int &x, const int &y) {
        return make_pair(b[x].count(), -P[x]) > make_pair(b[y].count(), -P[y]);
    });

    solve(0, 0, bitset <1024> ());
    cout << ans;
    return 0;
}