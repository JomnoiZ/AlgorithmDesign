#include <bits/stdc++.h>
using namespace std;

int K;

vector <vector <int>> matrix_multiply(vector <vector <int>> a, vector <vector <int>> b) {
    vector <vector <int>> c(2, vector <int> (2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % K;
            }
        }
    }
    return c;
}

vector <vector <int>> matrix_expo(vector <vector <int>> a, int N) {
    if (N == 0) return {{1, 0}, {0, 1}};

    vector <vector <int>> c = matrix_expo(a, N / 2);
    c = matrix_multiply(c, c);
    if (N % 2 == 1) c = matrix_multiply(a, c);
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    vector <vector <int>> a(2, vector <int> (2));

    cin >> N >> K;
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];

    vector <vector <int>> result = matrix_expo(a, N);
    cout << result[0][0] << ' ' << result[0][1] << ' ' << result[1][0] << ' ' << result[1][1];
    return 0;
}