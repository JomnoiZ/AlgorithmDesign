#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    double W;
    int N;
    cin >> W >> N;

    vector <double> v(N), w(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) cin >> w[i];

    vector <int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return v[a] * w[b] > v[b] * w[a];
    });

    double ans = 0;
    for (int i = 0; i < N; i++) {
        if (w[idx[i]] <= W) {
            ans += v[idx[i]];
            W -= w[idx[i]];
        }
        else {
            ans += W * v[idx[i]] / w[idx[i]];
            break;
        }
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}