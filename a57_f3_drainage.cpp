#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    vector <int> p(N);
    for (auto &x : p) cin >> x;

    sort(p.begin(), p.end());

    int cur = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (cur < p[i]) {
            ans++;
            cur = p[i] + L - 1;
        }
    }
    cout << ans;
    return 0;
}