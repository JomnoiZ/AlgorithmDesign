#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;

int parent[MAX_N];

int find_parent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_parent(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector <tuple <int, int, int>> edges;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.emplace_back(c, a, b);
    }

    iota(parent, parent + N, 0);
    sort(edges.begin(), edges.end());

    int cnt = N;
    vector <int> ans(N + 1);
    for (auto [c, a, b] : edges) {
        int u = find_parent(a), v = find_parent(b);
        if (u != v) {
            ans[--cnt] = c;
            parent[v] = u;
        }
    }

    while (Q--) {
        int D;
        cin >> D;

        cout << ans[D] << '\n';
    }
    return 0;
}