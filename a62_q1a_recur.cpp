#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300;

int table[MAX_N][MAX_N];

void solve(int x1, int y1, int x2, int y2, int b) {
    if (x1 == x2 and y1 == y2) {
        table[x1][y1] = b;
        return;
    }

    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;
    solve(x1, y1, mx, my, b);
    solve(x1, my + 1, mx, y2, b - 1);
    solve(mx + 1, y1, x2, my, b + 1);
    solve(mx + 1, my + 1, x2, y2, b);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int n = (1<<a);
    solve(0, 0, n - 1, n - 1, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << table[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}