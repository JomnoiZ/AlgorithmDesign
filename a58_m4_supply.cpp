#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector <int> D(K), E(K), L(K);
    for (int i = 0; i < K; i++) cin >> D[i] >> E[i] >> L[i];

    vector <int> idx(K);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return D[a] < D[b];
    });

    queue <int> plants, stores;
    for (int i = 0; i < K; i++) {
        int ans = 0;
        if (E[idx[i]] == 0) {
            if (!plants.empty()) {
                ans = plants.front();
                plants.pop();
            }
            else stores.push(L[idx[i]]);
        }
        else {
            if (!stores.empty()) {
                ans = stores.front();
                stores.pop();
            }
            else plants.push(L[idx[i]]);
        }
        cout << ans << '\n';
    }
    return 0;
}