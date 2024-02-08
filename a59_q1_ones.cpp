#include <bits/stdc++.h>
using namespace std;

int solve(int n, int l) {
    if (n < 11) return min(13 - n, n);
    
    int s = 1;
    for (int i = 0; i < l - 1; i++) s = s * 10 + 1;
    return min(solve(n - n / s * s, l - 1) + n / s * l, solve((n / s + 1) * s - n, l - 1) + (n / s + 1) * l);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    int s = 1, l = 1;
    while (s < n) s = s * 10 + 1, l++;
    cout << min(solve(n, l - 1), solve(s - n, l) + l);
    return 0;
}