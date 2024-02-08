#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;

vector <long long> a;

int solve(int l, int r, long long x) {
    if (l == r) return l;

    int mid = (l + r + 1) / 2;
    if (a[mid] <= x) return solve(mid, r, x);
    return solve(l, mid - 1, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        a[i] += a[i - 1] + k;
    }

    while (m--) {
        int l;
        long long b;
        cin >> l >> b;

        l++;
        int r = solve(l - 1, n, b + a[l - 1]);
        cout << a[r] - a[l - 1] - (r - l + 1) * k << '\n';
    }
    return 0;
}