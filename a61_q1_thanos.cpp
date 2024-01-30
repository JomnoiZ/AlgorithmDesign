#include <bits/stdc++.h>
using namespace std;

long long A, B;
vector <long long> a;

long long solve(long long l, long long r) {
    int cnt = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    if (cnt == 0) return A;
    
    long long res = cnt * B * (r - l + 1);

    if (l < r) {
        long long mid = (l + r) / 2;
        res = min(res, solve(l, mid) + solve(mid + 1, r));
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int p, k;
    cin >> p >> k >> A >> B;

    a.resize(k);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    
    cout << solve(1, 1<<p);
    return 0;
}