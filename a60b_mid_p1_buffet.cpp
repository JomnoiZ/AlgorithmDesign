#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int f, w, n;
    cin >> f >> w >> n;

    vector <int> food(f);
    for (auto &x : food) cin >> x;

    sort(food.begin(), food.end());

    int cur = 0, ans = 0;
    for (auto f : food) {
        if (cur < f) {
            cur = f + 2 * w;
            ans++;
        }
    }
    cout << ans;
    return 0;
}