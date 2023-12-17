#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> v, v2;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        v.push_back(x);
        v2.push_back(x);
    }

    sort(v2.begin(), v2.end());

    int cnt[4][4] = {};
    for (int i = 0; i < N; i++) cnt[v2[i]][v[i]]++;
    
    int ans = 0, sum = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            int t = min(cnt[i][j], cnt[j][i]);
            ans += t;
            sum += cnt[i][j] + cnt[j][i] - 2 * t;
        }
    }
    cout << ans + sum * 2 / 3;
    return 0;
}