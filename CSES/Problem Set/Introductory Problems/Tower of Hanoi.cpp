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

void move(int n, vector<ii> &m, int a = 1, int b = 3) {
    if (n == 1) {
        m.pb({a, b});
        return;
    }
    
    int r = 6 - a - b;

    move(n - 1, m, a, r);
    move(1, m, a, b);
    move(n - 1, m, r, b);
}

int main() {
	set_io("");

    int n; cin >> n;
    vector<ii> moves;
    move(n, moves);
    cout << moves.sz() << endl;
    for (auto m : moves) cout << m.fi << " " << m.se << endl;
}
