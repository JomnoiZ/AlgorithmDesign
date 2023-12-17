#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <pair <int, int>> intervals(N);
    for (auto &x : intervals) cin >> x.second;
    for (auto &x : intervals) cin >> x.first;

    sort(intervals.begin(), intervals.end());

    int end_time = 0, ans = 0;
    for (auto [e, s] : intervals) {
        if (end_time <= s) {
            end_time = e;
            ans++;
        }
    }
    cout << ans;
    return 0;
}