#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int,int>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ll mem[260][10];
ll f(int d, int n) {
    if (!d) return 1;
    else if (mem[d][n]) return mem[d][n];
    else if (!n) return mem[d][n] = f(d - 1, 6) + f(d - 1, 8);
    else return mem[d][n] = f(d - 1, n - 1);
}

int main() {
    set_io("");

    ll ans = 0;
    for (int i = 0; i < 300; i++) {
        int x; cin >> x;
        ans += f(256, x);
    }
    cout << ans << endl;
}
