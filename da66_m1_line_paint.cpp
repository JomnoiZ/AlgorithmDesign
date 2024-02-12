#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <pair <int, int>> vec;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        vec.emplace_back(a, b);
    }

    sort(vec.begin(), vec.end());

    int farthest = -1;
    for (int i = 0; i < N; i++) {
        if (farthest + 1 < vec[i].first) {
            if (farthest != -1) cout << farthest << ' ';
            cout << vec[i].first << ' ';
        }
        farthest = max(farthest, vec[i].second);
    }
    cout << farthest;
    return 0;
}