#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

vector <int> graph[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int ans = 0;
    queue <pair <int, int>> q;
    q.emplace(0, 0);
    visited[0] = true;
    while (!q.empty()) {
        auto [u, c] = q.front();
        q.pop();

        if (c == k) {
            ans++;
            continue;
        }
        for (auto v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.emplace(v, c + 1);
            }
        }
    }
    cout << ans;
    return 0;
}