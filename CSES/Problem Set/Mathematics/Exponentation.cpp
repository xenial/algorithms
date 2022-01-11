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

int modpow(int a, int b, int mod) {
    int h;
    if (b == 0) return 1 % mod;
    else if (b % 2) {
        h = modpow(a, b / 2, mod);
        h = h * h % mod;
    } else {
        h = modpow(a, b - 1, mod);
        h = h * a % mod;
    }
    return h;
}

ll solve(int a, int b) {
    int mod = 1000000007;
    return modpow(a, b, mod);
}

int main() {
    set_io("");

    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}