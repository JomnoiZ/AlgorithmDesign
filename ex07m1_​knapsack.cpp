#include <bits/stdc++.h>
using namespace std;

int N;
float W, ans;
float qsv[100];

struct Item {
    float v, w;

    bool operator<(const Item &o) const {
        return v * o.w > o.v * w;
    }
};
Item a[100];
vector <Item> a_greedy[100];

void solve(int i, float weight, float value) {
    if (i == N) return void(ans = max(ans, value));
    if (value + qsv[i] <= ans) return;

    float v_greedy = value, w_greedy = W - weight;
    for (auto &item : a_greedy[i]) {
        if (w_greedy >= item.w) {
            v_greedy += item.v;
            w_greedy -= item.w;
        }
        else {
            v_greedy += w_greedy * item.v / item.w;
            break;
        }
    }
    if (v_greedy <= ans) return;

    if (weight + a[i].w <= W) solve(i + 1, weight + a[i].w, value + a[i].v);
    solve(i + 1, weight, value);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> W >> N;

    for (int i = 0; i < N; i++) cin >> a[i].v;
    for (int i = 0; i < N; i++) cin >> a[i].w;
    
    sort(a, a + N);

    qsv[N - 1] = a[N - 1].v;
    for (int i = N - 2; i >= 0; i--) qsv[i] = qsv[i + 1] + a[i].v;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) a_greedy[i].push_back(a[j]);
        sort(a_greedy[i].begin(), a_greedy[i].end());
    }

    solve(0, 0.0, 0.0);
    cout << fixed << setprecision(5) << ans;
    return 0;
}