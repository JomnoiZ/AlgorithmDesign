#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> degree(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;

            degree[i] += a;
        }
    }

    vector <int> cnt(n + 1);
    int max_degree = 0;
    for (int i = 1; i <= n; i++) {
        max_degree = max(max_degree, degree[i]);
        cnt[degree[i]]++;
    }

    for (int i = 0; i <= max_degree; i++) cout << cnt[i] << ' ';
    return 0;
}