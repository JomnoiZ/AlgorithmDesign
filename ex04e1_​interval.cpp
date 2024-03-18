#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> s(N), e(N);
    for (int i = 0; i < N; i++) cin >> s[i];
    for (int i = 0; i < N; i++) cin >> e[i];

    vector <int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return e[a] < e[b];
    });

    int ans = 0, cur = 0;
    for (int i = 0; i < N; i++) {
        if (cur <= s[idx[i]]) {
            cur = e[idx[i]];
            ans++;
        }
    }
    cout << ans;
    return 0;
}