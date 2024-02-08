#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int X[MAX_N], Y[MAX_N];

vector <int> pareto(int l, int r) {
    if (l == r) return {l};

    int m = (l + r) / 2;
    vector <int> L = pareto(l, m), R = pareto(m + 1, r);
    
    int i = 0, j = 0;
    vector <int> result;
    while (i < L.size() or j < R.size()) {
        if (i == L.size()) result.push_back(R[j++]);
        else if (j == R.size()) result.push_back(L[i++]);
        else {
            if (!(X[L[i]] <= X[R[j]] and Y[L[i]] <= Y[R[j]])) result.push_back(L[i++]);
            else {
                while (i < L.size() and X[L[i]] <= X[R[j]] and Y[L[i]] <= Y[R[j]]) i++;
                result.push_back(R[j++]);
            }
        }
    }
    return result;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <pair <int, int>> point;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];

        point.emplace_back(X[i], Y[i]);
    }

    sort(point.begin(), point.end());

    for (int i = 0; i < N; i++) X[i] = point[i].first, Y[i] = point[i].second;

    cout << pareto(0, N - 1).size();
    return 0;
}