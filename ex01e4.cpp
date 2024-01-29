#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long X, N, K;
    cin >> X >> N >> K;

    long long res = 1;
    while (N > 0) {
        if (N % 2 == 1) res = res * X % K;

        X = X * X % K;
        N /= 2;
    }
    cout << res;
    return 0;
}