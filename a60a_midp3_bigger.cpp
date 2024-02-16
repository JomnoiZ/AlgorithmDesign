#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> dp(N + 1);
    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;

        dp[i] = max(dp[i - 1], dp[max(0, i - 3)] + c);
    }
    cout << dp[N];
    return 0;
}