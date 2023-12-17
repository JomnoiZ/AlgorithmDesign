#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;

int R, C;
int a[MAX_N][MAX_N];
string path;

void solve(int i, int j) {
    if (i < 1 or i > R or j < 1 or j > C or a[i][j] != 0) return;
    if (i == R and j == C) {
        cout << path << '\n';
        return;
    }

    a[i][j] = 2;
    path.push_back('A');
    solve(i, j + 1);
    path[path.size() - 1] = 'B';
    solve(i + 1, j);
    path[path.size() - 1] = 'C';
    solve(i - 1, j);
    path.pop_back();
    a[i][j] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) cin >> a[i][j];

    solve(1, 1);
    cout << "DONE";
    return 0;
}