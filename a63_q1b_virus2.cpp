#include <bits/stdc++.h>
using namespace std;

vector <int> a;

bool solve(int l, int r) {
    if (l + 1 == r) return true;

    int mid = (l + r) / 2;
    bool ok = solve(l, mid) & solve(mid + 1, r);
    
    int cnt1 = 0, cnt2 = 0;
    for (int i = l; i <= mid; i++) cnt1 += a[i];
    for (int i = mid + 1; i <= r; i++) cnt2 += a[i];
    if (abs(cnt1 - cnt2) > 1) ok = false;
    return ok;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    a.resize(1<<k);
    while (n--) {
        for (int i = 0; i < (1<<k); i++) cin >> a[i];

        if (solve(0, (1<<k) - 1) == true) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}