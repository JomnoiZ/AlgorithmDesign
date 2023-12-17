#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int INF = 1e9 + 7;

int a[MAX_N][MAX_N];
vector <int> vec[2 * MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];

            vec[i - j + 1000].push_back(a[i][j]);
        }
    }

    int ans = -INF;
    for (int i = 1; i < 2000; i++) {
        int sum = 0;
        for (auto v : vec[i]) {
            sum = max(sum + v, v);
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
    return 0;
}