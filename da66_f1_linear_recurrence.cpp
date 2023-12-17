#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int MOD = 32717;

int c[MAX_N], a[MAX_N], R[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = 0; i < k; i++) cin >> a[i];

    for (int i = 0; i < k; i++) R[i] = a[i];
    for (int i = k; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            R[i] = (R[i] + c[j] * R[i - j] % MOD) % MOD;
        }
    }
    cout << R[n];
    return 0;
}