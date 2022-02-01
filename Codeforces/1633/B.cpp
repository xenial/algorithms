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
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int main() {
	set_io("");

    int T; cin >> T;

    while (T--) {
        string S; cin >> S;

        if (S.sz() < 3) {
            cout << 0 << endl;
            continue;
        }

        int oc, zc;
        oc = zc = 0;

        for (auto c : S) {
            if (c == '0') zc++;
            else oc++;
        }

        cout << min(zc, oc) - (zc == oc) << endl;
    }
}
