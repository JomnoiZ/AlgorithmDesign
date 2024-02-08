#include <bits/stdc++.h>
using namespace std;

int k;
vector <vector <int>> dp;
vector <vector <int>> edge;

int solve(int u) {
    dp[u][0] = 1;
    int res = 0;
    for (auto v : edge[u]) {
        res += solve(v);
        for (int i = 0; i < k; i++) res += dp[u][i] * dp[v][k - i - 1];
        for (int i = 1; i <= k; i++) dp[u][i] += dp[v][i - 1];
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n >> k;

    edge.resize(n + 1);
    dp = vector <vector <int>> (n + 1, vector <int> (k + 1));
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
    }
    cout << solve(1);
    return 0;
}