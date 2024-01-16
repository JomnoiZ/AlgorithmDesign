#include <bits/stdc++.h>
using namespace std;

int a, b;
string s;

void solve(int c, int len) {
    if (c > a or len > b) return;
    if (c == a and len == b) {
        cout << s << '\n';
        return;
    }

    s[len] = '1';
    solve(c + 1, len + 1);
    s[len] = '0';
    solve(c, len + 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> a >> b;

    s = string(b, '0');

    solve(0, 0);
    return 0;
}