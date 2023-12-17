#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    double W;
    int N;
    cin >> W >> N;

    vector <double> w(N), v(N);
    vector <int> idx(N);
    for (auto &x : v) cin >> x;
    for (auto &x : w) cin >> x;

    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](const int &x, const int &y) {
        return v[x] * w[y] > w[x] * v[y];
    });

    double ans = 0;
    for (int i = 0; i < N; i++) {
        if (W >= w[idx[i]]) {
            W -= w[idx[i]];
            ans += v[idx[i]];
        }
        else {
            ans += v[idx[i]] * W / w[idx[i]];
            break;
        }
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}