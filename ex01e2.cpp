#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const long long INF = 1e18 + 7;

int A[MAX_N];

long long solve(int l, int r) {
    if (l == r) return A[l];

    int mid = (l + r) / 2;
    long long res = max(solve(l, mid), solve(mid + 1, r));

    long long maxLeft = -INF, maxRight = -INF;
    long long sumLeft = 0, sumRight = 0;
    for (int i = mid; i >= l; i--) {
        sumLeft += A[i];
        maxLeft = max(maxLeft, sumLeft);
    }
    for (int i = mid + 1; i <= r; i++) {
        sumRight += A[i];
        maxRight = max(maxRight, sumRight);
    }
    res = max(res, maxLeft + maxRight);
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> A[i];

    cout << solve(1, N);
    return 0;
}