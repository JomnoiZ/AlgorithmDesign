#include <bits/stdc++.h>
using namespace std;

int N, ans;

void solve(int i, int s) {
    if (s > N) return;
    if (s == N) {
        ans++;
        return;
    }
    for (int j = i; j <= N; j++) solve(j, s + j);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) solve(i, i);
    cout << ans;
    return 0;
}