#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<vector<int>> pf;

int solve(int y1, int x1, int y2, int x2) {
    return pf[y2][x2] - pf[y1-1][x2] - pf[y2][x1-1] + pf[y1-1][x1-1];
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, q; cin >> n >> q;
    pf = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        string row; cin >> row;
        for (int j = 1; j <= n; j++) {
            if (row[j - 1] == '*') pf[i][j] = 1;
            pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + pf[i][j];
        }
    }
    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << solve(y1, x1, y2, x2) << endl;
    }
}