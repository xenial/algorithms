#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    
}

int main() {
    set_io("");

    int n; cin >> n;
    vector<vector<int>> s(n, vector<int>(n)), t(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> s[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> t[i][j];
    }
}