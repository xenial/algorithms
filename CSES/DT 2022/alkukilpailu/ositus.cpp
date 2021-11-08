#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

string s;

bool valid(int mask) {
    vector<bool> open(26, false);
    for (int i = 0; i < s.sz(); i++) {
        int ci = s[i] - 'a';
        if (open[ci]) return false;
        open[ci] = true;

        if (mask & (1 << s.sz() - 2 - i)) open = vector<bool>(26, false);
    }
    return true;
}

int main() {
    set_io("");

    cin >> s;

    int ans = 0;
    for (int i = 0; i < (1 << s.sz() - 1); i++) {
        ans += valid(i);
    }
    cout << ans << endl;
}