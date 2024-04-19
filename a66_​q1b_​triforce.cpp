#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;

int table[MAX_N][MAX_N];

int check(int a, int b, int c) {
    if (a == 0 or b == 0 or c == 0) return 0;
    if (a == b or a == c) return a;
    if (b == c) return b;
    return 0;
}

int solve(int x1, int x2, int y1, int y2) {
    if (x1 + 1 == x2 and y1 + 1 == y2) {
        if (table[x2][y2] != 0) return 0;

        return check(table[x1][y1], table[x1][y2], table[x2][y1]);
    }

    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;

    for (int i = mx + 1; i <= x2; i++) {
        for (int j = my + 1; j <= y2; j++) {
            if (table[i][j] != 0) return 0;
        }
    }

    int a = solve(x1, mx, y1, my);
    int b = solve(x1, mx, my + 1, y2);
    int c = solve(mx + 1, x2, y1, my);
    return check(a, b, c);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int q = 0; q < 3; q++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> table[i][j];
            }
        }

        cout << solve(1, n, 1, n) << '\n';
    }
    return 0;
}