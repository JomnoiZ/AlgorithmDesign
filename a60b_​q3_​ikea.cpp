#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector <pair <int, int>> edges;
    while (m--) {
        int a, b;
        cin >> a >> b;

        edges.emplace_back(a, b);
    }

    for (int q = 0; q < 5; q++) {
        vector <int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;

            pos[s] = i;
        }

        bool ok = true;
        for (auto [a, b] : edges) {
            if (pos[a] > pos[b]) ok = false;
        }

        if (ok == true) cout << "SUCCESS\n";
        else cout << "FAIL\n";
    }
    return 0;
}