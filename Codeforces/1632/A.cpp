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
        int N; cin >> N;
        string S; cin >> S;

        if (N == 1) {
            cout << "YES" << endl;
            continue;
        }

        int oc = 0;
        for (auto c : S) if (c == '1') oc++;

        if (N == 2) {
            cout << (oc == 1 ? "YES" : "NO") << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}
