#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> original(N), sorted(N);
    for (int i = 0; i < N; i++) {
        cin >> original[i];
        sorted[i] = --original[i];
    }

    sort(sorted.begin(), sorted.end());

    int cnt[3][3] = {};
    for (int i = 0; i < N; i++) cnt[sorted[i]][original[i]]++;

    int ans = 0, sum = 0;
    for (int i = 0; i < 3; i++) for (int j = i + 1; j < 3; j++) {
        int c = min(cnt[i][j], cnt[j][i]);
        ans += c;
        sum += cnt[i][j] + cnt[j][i] - 2 * c;
    }
    cout << ans + sum * 2 / 3;
    return 0;
}