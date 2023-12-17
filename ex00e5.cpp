#include <bits/stdc++.h>
using namespace std;

int n, k;
bool b[25];

void solve(int i, int c, bool valid) {
    if (i == n) {
        if (valid == true) {
            for (int i = 0; i < n; i++) cout << b[i];
            cout << '\n';
        }
        return;
    }
    b[i] = 0;
    solve(i + 1, 0, valid);
    b[i] = 1;
    solve(i + 1, c + 1, valid | (c + 1 == k));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;

    solve(0, 0, k == 0);
    return 0;
}