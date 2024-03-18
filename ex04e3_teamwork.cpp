#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <int> a(M);
    for (int i = 0; i < M; i++) cin >> a[i];

    sort(a.begin(), a.end());

    priority_queue <int, vector <int>, greater <int>> pq;
    for (int i = 0; i < N; i++) pq.push(0);

    double ans = 0;
    for (int i = 0; i < M; i++) {
        int u = pq.top();
        pq.pop();

        ans += u + a[i];
        pq.push(u + a[i]);
    }
    cout << fixed << setprecision(3) << ans / M;
    return 0;
}