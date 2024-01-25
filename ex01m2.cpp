#include <bits/stdc++.h>
using namespace std;

vector <int> A;

long long solve(int l, int r) {
    if (l == r) return 0;

    int mid = (l + r) / 2;
    long long res = solve(l, mid) + solve(mid + 1, r);

    vector <int> L, R;
    for (int i = l; i <= mid; i++) L.push_back(A[i]);
    for (int i = mid + 1; i <= r; i++) R.push_back(A[i]);

    int i = 0, j = 0, k = l;
    while (i < L.size() and j < R.size()) {
        if (L[i] <= R[j]) A[k++] = L[i++];
        else res += L.size() - i, A[k++] = R[j++];
    }
    while (i < L.size()) A[k++] = L[i++];
    while (j < R.size()) A[k++] = R[j++];

    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    A.resize(N);
    for (auto &x : A) cin >> x;

    cout << solve(0, N - 1);
    return 0;
}