#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector <int> p(m), h(m), idx(m);
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> h[i];
    for (int i = 0; i < m; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return p[a] < p[b];
    });

    int i = 0, j = 0;
    while (i <= n and j < m and k > 0) {
        int x = max(i + 1, p[idx[j]] - w);
        if (x <= n and x - w <= p[idx[j]] and h[idx[j]] > 0) {
            h[idx[j]]--;
            k--;
            i = x;
        }
        else j++;
    }

    int sum = 0;
    for (int i = 0; i < m; i++) sum += h[i];
    cout << sum;
    return 0;
}