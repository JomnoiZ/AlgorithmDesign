#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    while (m--) {
        int k;
        cin >> k;

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) break;
            if (a[i] > k) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}