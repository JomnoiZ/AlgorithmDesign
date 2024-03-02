#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int N;
long long Y[MAX_N];

int solve(long long l, long long r) {
    int cnt = upper_bound(Y + 1, Y + N + 1, r) - lower_bound(Y + 1, Y + N + 1, l);
    if (cnt == 0) return 0;
    if (r - l + 1 < 3) return cnt;

    long long u = (r - l + 1) / 3;
    long long v = (r - l + 2) / 3;
    int r1 = solve(l, l + u - 1);
    int r2 = solve(l + u, l + u + v - 1);
    int r3 = solve(l + u + v, r);
    return r1 + r2 + r3 - min({r1, r2, r3}) + cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long W;
    cin >> W >> N;

    for (int i = 1; i <= N; i++) cin >> Y[i];

    sort(Y + 1, Y + N + 1);

    cout << solve(1ll, W);
    return 0;
}