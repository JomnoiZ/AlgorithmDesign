#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector <vector <int>> a(N + 1, vector <int> (M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];

            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    while (K--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        r1++, c1++, r2++, c2++;
        cout << a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1] << '\n';
    }
    return 0;
}