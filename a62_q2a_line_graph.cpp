#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> graph[MAX_N];
bool visited[MAX_N];
int degree[MAX_N];
int cnt[3];

void dfs(int u) {
    if (degree[u] > 2) cnt[2]++;
    else if (degree[u] < 2) cnt[degree[u]]++;
    for (auto v : graph[u]) {
        if (visited[v] == false) {
            visited[v] = true;
            dfs(v);
        }
    }
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
        degree[a]++, degree[b]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            cnt[0] = cnt[1] = cnt[2] = 0;
            visited[i] = true;
            dfs(i);
            if ((cnt[0] == 1 or cnt[1] == 2) and cnt[2] == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}