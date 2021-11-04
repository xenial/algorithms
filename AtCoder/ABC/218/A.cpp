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

bool solve(int n, string s) {
    return s[n-1] == 'o';
}

int main() {
    set_io("");

    int n; cin >> n;
    string s; cin >> s;
    cout << (solve(n, s) ? "Yes" : "No");
}