#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> vec;

int solve(int l, int r, int k) {
    if (l + 1 == r or k == 1) {
        for (int i = l; i < r; i++) vec[i] = i - l + 1;
        return 1;
    }

    int mid = (l + r) / 2;
    int val1 = solve(l, mid, k - 2);
    int val2 = solve(mid, r, k - 1 - val1);

    for (int i = l; i < mid; i++) vec[i] += r - mid;
    return val1 + val2 + 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vec.resize(n);
    reverse(vec.begin(), vec.end());

    int x = solve(0, n, k);
    if (x != k) cout << "-1\n";
    else for (auto v : vec) cout << v << ' ';
    return 0;
}