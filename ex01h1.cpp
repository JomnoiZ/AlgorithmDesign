#include <bits/stdc++.h>
using namespace std;

vector <int> dp;

int solve(int l, int r, int x) {
    if (l == r) return l;

    int mid = (l + r) / 2;
    if (dp[mid] >= x) return solve(l, mid, x);
    return solve(mid + 1, r, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(3);
    for (int i = 3, j = 2;; i++) {
        if (i > dp[j]) j++;

        dp.push_back(dp.back() + j);
        if (dp.back() > 2e9) break;
    }

    int N;
    cin >> N;

    while (N--) {
        int X;
        cin >> X;
        
        cout << solve(1, dp.size() - 1, X) << '\n';
    }
    return 0;
}