#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;
const int INF = 1e9 + 7;

int A[MAX_N];

struct Node {
    int ans, ansMax, ansMin, maxLeftSide, maxRightSide;
};

Node solve(int l, int r) {
    if (l == r) return {max(A[l], 0), max(A[l], 0), max(A[l], 0), max(A[l], 0), max(A[l], 0)};

    int mid = (l + r) / 2;
    Node L = solve(l, mid);
    Node R = solve(mid + 1, r);

    int sumLeft = 0, sumRight = 0;
    int maxLeft = 0, maxRight = 0;
    int minLeft = 0, minRight = 0;
    for (int i = mid; i >= l; i--) {
        sumLeft += A[i];
        maxLeft = max(maxLeft, sumLeft);
        minLeft = min(minLeft, sumLeft);
    }
    for (int i = mid + 1; i <= r; i++) {
        sumRight += A[i];
        maxRight = max(maxRight, sumRight);
        minRight = min(minRight, sumRight);
    }

    int ans_ = max({L.ans, R.ans, L.ansMax + R.ansMax, L.maxRightSide + maxRight, maxLeft + R.maxLeftSide});
    int ansMax_ = max({L.ansMax, R.ansMax, maxLeft + maxRight});
    int ansMin_ = min({L.ansMin, R.ansMin, minLeft + minRight});
    int maxLeftSide_ = max({L.maxLeftSide, sumLeft - L.ansMin + maxRight, sumLeft - minLeft + R.ansMax, sumLeft + R.maxLeftSide});
    int maxRightSide_ = max({R.maxRightSide, maxLeft + sumRight - R.ansMin, L.ansMax + sumRight - minRight, L.maxRightSide + sumRight});
    return {ans_, ansMax_, ansMin_, maxLeftSide_, maxRightSide_};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    int maxElement = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        maxElement = max(maxElement, A[i]);
    }

    if (maxElement < 0) cout << maxElement;
    else cout << solve(1, n).ans;
    return 0;
}