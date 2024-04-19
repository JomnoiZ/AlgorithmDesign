#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 20;

int n, m, cnt, ans;
vector <int> a[MAX_M], idx;
int mp[MAX_N];

void solve(int i, int c) {
    if (c >= ans) return;
    if (cnt == n) return void(ans = c);
    
    for (int j = i; j < m; j++) {
        for (auto v : a[idx[j]]) if (mp[v]++ == 0) cnt++;
        solve(j + 1, c + 1);
        for (auto v : a[idx[j]]) if (--mp[v] == 0) cnt--;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        idx.push_back(i);
        a[i].resize(k);
        for (auto &x : a[i]) {
            cin >> x;
            x--;
        }
    }

    sort(idx.begin(), idx.end(), [&](const int &x, const int &y) {
        return a[x].size() > a[y].size();
    });

    ans = m;
    solve(0, 0);
    cout << ans;
    return 0;
}