#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;

int cnt_disc, cnt_scc;
vector <int> graph[MAX_N], graph2[MAX_N];
int disc[MAX_N], low[MAX_N], scc[MAX_N], sz[MAX_N];
bool on_stack[MAX_N];
stack <int> nodes;
int indegree[MAX_N], Rank[MAX_N];
map <int, bool> chk[MAX_N];

// This is out of scope from Algorithm Design, you don't need to understand what I did :)
void tarjan(int u) {
    disc[u] = low[u] = ++cnt_disc;
    on_stack[u] = true;
    nodes.push(u);
    for (auto &v : graph[u]) {
        if (disc[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (on_stack[v] == true) low[u] = min(low[u], disc[v]);
    }
    if (disc[u] == low[u]) {
        int now;
        do {
            now = nodes.top();
            nodes.pop();

            scc[now] = cnt_scc;
            sz[cnt_scc]++;
            on_stack[now] = false;
        } while (u != now);
        cnt_scc++;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, P;
    cin >> N >> P;

    while (P--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    for (int i = 0; i < N; i++) {
        if (disc[i] == 0) tarjan(i);
    }
    for (int u = 0; u < N; u++) {
        for (auto &v : graph[u]) {
            int a = scc[u], b = scc[v];
            if (a == b or chk[a].count(b)) continue;

            chk[a][b] = true;
            graph2[a].push_back(b);
            indegree[b]++;
        }
    }

    queue <int> q;
    for (int i = 0; i < cnt_scc; i++) {
        if (indegree[i] == 0) {
            Rank[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : graph2[u]) {
            if (--indegree[v] == 0) {
                Rank[v] = Rank[u] + 1;
                q.push(v);
            }
        }
    }

    map <int, int> cnt_rank;
    for (int i = 0; i < cnt_scc; i++) cnt_rank[Rank[i]] += sz[i];
    
    for (auto [r, c] : cnt_rank) cout << c << ' ';
    return 0;
}