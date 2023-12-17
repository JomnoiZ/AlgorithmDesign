#include <bits/stdc++.h>
using namespace std;

int N, ans;
bool col[15], d1[30], d2[50];

void solve(int r) {
    if (r == N) {
        ans++;
        return;
    }
    for (int c = 0; c < N; c++) {
        if (col[c] == false and d1[r + c] == false and d2[15 + r - c] == false) {
            col[c] = d1[r + c] = d2[15 + r - c] = true;
            solve(r + 1);
            col[c] = d1[r + c] = d2[15 + r - c] = false;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    solve(0);
    cout << ans;
    return 0;
}