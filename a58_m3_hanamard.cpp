#include <bits/stdc++.h>
using namespace std;

vector <int> v;

vector <long long> solve(int l, int r) {
    if (l == r) return {v[l]};

    int m = (l + r) / 2;
    vector <long long> res[4];
    res[0] = solve(l, m);
    res[1] = solve(m + 1, r);
    for (int i = 0; i < m - l + 1; i++) {
        res[2].push_back(res[0][i]);
        res[3].push_back(-res[1][i]);
    }
    for (int i = 0; i < m - l + 1; i++) {
        res[0][i] += res[1][i];
        res[2][i] += res[3][i];
    }
    res[0].insert(res[0].end(), res[2].begin(), res[2].end());
    return res[0];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    v.resize(n);
    for (auto &x : v) cin >> x;

    vector <long long> ans(solve(0, n - 1));
    for (auto x : ans) cout << x << ' ';
    return 0;
}