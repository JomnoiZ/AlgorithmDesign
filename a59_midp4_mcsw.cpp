#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, w;
    cin >> n >> w;

    int sum = 0, ans = -INF;
    priority_queue <pair <int, int>> pq;
    pq.emplace(0, 0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        while (!pq.empty() and i - pq.top().second + 1 > w) pq.pop();

        sum += a;
        ans = max(ans, sum + pq.top().first);

        pq.emplace(-sum, i);
    }
    cout << ans;
    return 0;
}