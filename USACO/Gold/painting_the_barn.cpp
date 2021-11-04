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

    int n, k; cin >> n >> k;
    
}