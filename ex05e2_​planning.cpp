#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

vector <int> graph[MAX_N];
int indegree[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;

        indegree[i] = m;
        while (m--) {
            int x;
            cin >> x;

            graph[x].push_back(i);
        }
    }

    queue <int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << ' ';
        for (auto v : graph[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return 0;
}