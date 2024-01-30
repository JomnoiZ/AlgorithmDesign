#include <bits/stdc++.h>
using namespace std;

vector <tuple <int, int, int>> ans;

void solve(int x1, int x2, int y1, int y2, int x, int y) {
    if (x1 == x2 and y1 == y2) return;

    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    int type;

    if (x <= xm and y <= ym) {
        type = 0;
        solve(x1, xm, y1, ym, x, y);
        solve(x1, xm, ym + 1, y2, xm, ym + 1);
        solve(xm + 1, x2, y1, ym, xm + 1, ym);
        solve(xm + 1, x2, ym + 1, y2, xm + 1, ym + 1);
    }
    else if (x <= xm and y > ym) {
        type = 1;
        solve(x1, xm, y1, ym, xm, ym);
        solve(x1, xm, ym + 1, y2, x, y);
        solve(xm + 1, x2, y1, ym, xm + 1, ym);
        solve(xm + 1, x2, ym + 1, y2, xm + 1, ym + 1);
    }
    else if (x > xm and y <= ym) {
        type = 2;
        solve(x1, xm, y1, ym, xm, ym);
        solve(x1, xm, ym + 1, y2, xm, ym + 1);
        solve(xm + 1, x2, y1, ym, x, y);
        solve(xm + 1, x2, ym + 1, y2, xm + 1, ym + 1);
    }
    else if (x > xm and y > ym) {
        type = 3;
        solve(x1, xm, y1, ym, xm, ym);
        solve(x1, xm, ym + 1, y2, xm, ym + 1);
        solve(xm + 1, x2, y1, ym, xm + 1, ym);
        solve(xm + 1, x2, ym + 1, y2, x, y);
    }
    ans.emplace_back(type, ym, xm);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, X, Y;
    cin >> L >> X >> Y;

    solve(0, L - 1, 0, L - 1, Y, X);

    cout << ans.size() << '\n';
    for (auto [t, y, x] : ans) cout << t << ' ' << y << ' ' << x << '\n';
    return 0;
}