#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 55;

vector <int> graph[MAX_N];
int color[MAX_N];
bool visited[MAX_N];

bool dfs(int u, int k) {
    visited[u] = true;
    vector <bool> has_color(k);
    for (auto v : graph[u]) {
        if (visited[v] == true) has_color[color[v]] = true;
    }

    for (int c = 0; c < k; c++) {
        if (has_color[c] == true) continue;

        color[u] = c;
        bool ok = true;
        for (auto v : graph[u]) {
            if (visited[v] == false and dfs(v, k) == false) {
                ok = false;
                break;
            }
        }
        if (ok == true) return true;
    }
    visited[u] = false;
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        bool ok = true;
        for (int i = 0; i < n; i++) color[i] = -1, visited[i] = false;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false and dfs(i, mid) == false) {
                ok = false;
                break;
            }
        }

        if (ok == true) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}