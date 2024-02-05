#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
const int INF = 1e9 + 7;

int w;
int a[MAX_N];

int solve(int l, int r) {
    if (l == r) return a[l];

    int mid = (l + r) / 2;
    int res = max(solve(l, mid), solve(mid + 1, r));

    vector <int> L;
    L.push_back(-INF);
    int sum = 0, maxRight = 0;
    for (int i = mid; i >= max(l, mid - w + 2); i--) {
        sum += a[i];
        L.push_back(max(L.back(), sum));
    }

    sum = 0;
    for (int i = mid + 1; i <= min(r, mid + w); i++) {
        sum += a[i];
        maxRight = max(maxRight, sum);
        res = max(res, L[min(w - i + mid, mid - l)] + maxRight);
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n >> w;

    for (int i = 1; i <= n; i++) cin >> a[i];
    
    cout << solve(1, n);
    return 0;
}