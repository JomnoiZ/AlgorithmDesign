#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MOD = 32717;

int dp[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) cin >> dp[i];
    for (int i = k + 1; i <= n; i++) {
        int p;
        cin >> p;

        while (p--) {
            int b;
            cin >> b;

            if (i - b >= 0) dp[i] = (dp[i] + dp[i - b]) % MOD;
        }
    }
    
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    return 0;
}