#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int M;
int order[MAX_N], dist[MAX_N];

int cost(int a, int b) {
    if (a > b) swap(a, b);
    return min(dist[b - 1] - dist[a - 1], dist[M] - dist[b - 1] + dist[a - 1]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> order[i];
        order[i]++;
    }
    order[M] = order[0];
    for (int i = 1; i <= M; i++) {
        cin >> dist[i];
        dist[i] += dist[i - 1];
    }

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        A++, B++;
        int ans = 0;
        for (int i = 1; i <= M; i++) {
            ans += min({cost(order[i - 1], order[i]), 
                        cost(order[i - 1], A) + cost(order[i], B), 
                        cost(order[i - 1], B) + cost(order[i], A)});
        }
        cout << ans << '\n';
    }
    return 0;
}