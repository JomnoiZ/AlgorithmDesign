#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;
const int INF = 1e9 + 7;

int A[MAX_N], dp[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i];

    int sum = 0;
    dp[n + 1] = -INF;
    for (int i = n; i >= 1; i--) {
        sum += A[i];
        dp[i] = max(dp[i + 1], sum);
        sum = max(sum, 0);
    }

    sum = 0;
    int maxLeft = -INF, ans = dp[1];
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        maxLeft = max(maxLeft, sum);
        ans = max(ans, maxLeft + dp[i + 1]);
        sum = max(sum, 0);
    }
    cout << ans;
    return 0;
}