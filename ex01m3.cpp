#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int N;
int T[MAX_N];

long long solve(long long l, long long r, long long c) {
    if (l == r) return l;

    long long m = (l + r) / 2, sum = 0;
    for (int i = 1; i <= N; i++) sum += m / T[i];

    if (sum >= c) return solve(l, m, c);
    return solve(m + 1, r, c);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A;
    cin >> N >> A;

    for (int i = 1; i <= N; i++) cin >> T[i];

    while (A--) {
        long long c;
        cin >> c;

        cout << solve(0, 1e12, c - N) << '\n';
    }
    return 0;
}