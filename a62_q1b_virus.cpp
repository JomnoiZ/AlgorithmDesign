#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300;

int pat[MAX_N];

bool solve(int l, int r) {
    if (l + 1 == r) return pat[l] == 0 and pat[r] == 1;

    int m = (l + r) / 2;
    if (solve(m + 1, r) == false) return false;
    if (solve(l, m) == true) return true;
    
    reverse(pat + l, pat + m + 1);
    bool res = solve(l, m);
    reverse(pat + l, pat + m + 1);
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    while (n--) {
        for (int i = 0; i < (1<<k); i++) cin >> pat[i];

        if (solve(0, (1<<k) - 1) == true) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}