#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    while (m--) {
        int q;
        cin >> q;

        bool ok = false;
        for (int i = 0; i < n - 2; i++) {
            if (ok == true) break;

            int j = i + 1, k = n - 1;
            while (j < k) {
                if (a[i] + a[j] + a[k] == q) {
                    ok = true;
                    break;
                }

                if (a[i] + a[j] + a[k] < q) j++;
                else k--;
            }
        }

        if (ok == true) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}