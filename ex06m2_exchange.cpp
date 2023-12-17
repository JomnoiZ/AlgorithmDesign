#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector <vector <double>> R(N, vector <double> (N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> R[i][j];
            }
        }
        
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    R[i][j] = max(R[i][j], R[i][k] * R[k][j]);
                }
            }
        }

        bool ok = false;
        for (int i = 0; i < N; i++) {
            if (R[i][i] > 1.0) ok = true;
        }

        if (ok == true) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}