#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25;

int n;
vector <int> g[MAX_N];
bool visited[MAX_N];
int vec[MAX_N];

void solve(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) cout << vec[j] << ' ';
        cout << '\n';
        return;
    }

    for (int j = 0; j < n; j++) {
        if (visited[j] == false) {
            bool ok = true;
            for (auto v : g[j]) ok &= visited[v];

            visited[j] = true;
            vec[i] = j;
            if (ok == true) solve(i + 1);
            visited[j] = false;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (auto v : g[i]) ok &= visited[v];

        visited[i] = true;
        vec[0] = i;
        if (ok == true) solve(1);
        visited[i] = false;
    }
    return 0;
}