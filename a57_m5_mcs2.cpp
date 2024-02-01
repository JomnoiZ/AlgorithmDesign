#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

int A[MAX_N];

int solve(int l, int r) {
    if (l == r) return A[l];

    int mid = (l + r) / 2;
    int res = min(solve(l, mid), solve(mid + 1, r));

    int minLeft = INF, minRight = INF;
    int sumLeft = 0, sumRight = 0;
    for (int i = mid; i >= l; i--) {
        sumLeft += A[i];
        minLeft = min(minLeft, sumLeft);
    } 
    for (int i = mid + 1; i <= r; i++) {
        sumRight += A[i];
        minRight = min(minRight, sumRight);
    }
    res = min(res, minLeft + minRight);

    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    int sum = 0, maxEle = -INF;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        sum += A[i];
        maxEle = max(maxEle, A[i]);
    }

    if (maxEle <= 0) cout << maxEle;
    else cout << sum - solve(1, N);
    return 0;
}