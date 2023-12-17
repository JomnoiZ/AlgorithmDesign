#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;

int a[MAX_N], parent[MAX_N];

int find_parent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_parent(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <tuple <int, int, int>> edges;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges.emplace_back(a[i] ^ a[j], i, j);
        }
    }

    sort(edges.rbegin(), edges.rend());

    long long ans = 0;
    iota(parent + 1, parent + n + 1, 1);
    for (auto [w, a, b] : edges) {
        int u = find_parent(a), v = find_parent(b);
        if (u != v) {
            ans += w;
            parent[v] = u;
        }
    }
    cout << ans;
    return 0;
}