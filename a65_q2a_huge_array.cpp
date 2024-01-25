#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    map <int, long long> mp;
    for (int i = 0; i < N; i++) {
        int x, c;
        cin >> x >> c;

        mp[x] += c;
    }

    vector <pair <long long, int>> vec;
    vec.emplace_back(0, 0);
    for (auto [k, v] : mp) vec.emplace_back(vec.back().first + v, k);

    while (Q--) {
        long long p;
        cin >> p;

        auto it = lower_bound(vec.begin(), vec.end(), make_pair(p, -1));
        cout << it->second << '\n';
    }
    return 0;
}