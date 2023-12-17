#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> graph[MAX_N];
int degree[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    queue <int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : graph[u]) {
            degree[u]--;
            if (--degree[v] == 1) q.push(v);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] > 1) ans++;
    }
    cout << ans;
    return 0;
}