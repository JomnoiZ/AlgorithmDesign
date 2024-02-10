#include <bits/stdc++.h>
using namespace std;

vector <int> position;

int solve(int l, int r, int x) {
    if (l == r) return l;

    int mid = (l + r) / 2;
    if (position[mid] >= x) return solve(l, mid, x);
    return solve(mid + 1, r, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    position.push_back(0);
    position.push_back(1);
    position.push_back(3);
    for (int i = 3, j = 2;; i++) {
        if (i > position[j]) j++;

        position.push_back(position.back() + j);
        if (position.back() > 2e9) break;
    }

    int N;
    cin >> N;

    while (N--) {
        int X;
        cin >> X;
        
        cout << solve(1, position.size() - 1, X) << '\n';
    }
    return 0;
}