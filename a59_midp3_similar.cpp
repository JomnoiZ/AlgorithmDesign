#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b) {
    int n = a.size();
    if (n == 1) return a == b;
    if (a == b) return true;

    int m = n / 2;
    return (solve(a.substr(0, m), b.substr(0, m)) && solve(a.substr(m, m), b.substr(m, m))) || 
           (solve(a.substr(0, m), b.substr(m, m)) && solve(a.substr(m, m), b.substr(0, m)));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if (solve(a, b) == true) cout << "YES";
    else cout << "NO";
    return 0;
}