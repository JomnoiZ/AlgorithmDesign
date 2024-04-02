#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 7;
int d[5][2] = {{-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

int K;

vector <vector <long long>> multiply(vector <vector <long long>> a, vector <vector <long long>> b) {
    vector <vector <long long>> c(K, vector <long long> (K, INF));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < K; k++) {
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}

vector <vector <long long>> expo(vector <vector <long long>> a, int b) {
    if (b == 1) return a;

    vector <vector <long long>> c = expo(a, b / 2);
    c = multiply(c, c);
    if (b % 2 == 1) c = multiply(c, a);
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, P;
    cin >> N >> K >> P;

    vector <vector <long long>> cost(K, vector <long long> (5));
    for (int i = 0; i < K; i++) for (int j = 0; j < 5; j++) cin >> cost[i][j];

    vector <vector <vector <long long>>> dp(K, vector <vector <long long>> (K, vector <long long> (2, INF)));
    for (int i = 0; i < K; i++) {
        priority_queue <tuple <long long, int, int>> pq;
        pq.emplace(0, i, 0);
        dp[i][i][0] = 0;
        while (!pq.empty()) {
            auto [dist, k, n] = pq.top();
            pq.pop();

            for (int j = 0; j < 5; j++) {
                int nk = (k + d[j][0] + K) % K, nn = n + d[j][1];
                if (nn < 2 and dp[i][k][n] + cost[k][j] < dp[i][nk][nn]) {
                    dp[i][nk][nn] = dp[i][k][n] + cost[k][j];
                    pq.emplace(-dp[i][nk][nn], nk, nn);
                }
            }
        }
    }

    vector <vector <long long>> mat(K, vector <long long> (K));
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) mat[i][j] = dp[i][j][1];

    cout << expo(mat, N - 1)[0][P];
    return 0;
}