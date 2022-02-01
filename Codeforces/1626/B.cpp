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

    int t; cin >> t;

    while (t--) {
        string x; cin >> x;

        bool tn = false;
        for (int i = x.sz() - 1; i > 0; i--) {
            int s = x[i] - '0' + x[i-1] - '0';
            if (s >= 10) {
                string b = to_string(s);
                x[i-1] = b[0];
                x[i] = b[1];
                tn = true;
                break;
            }
        }

        if (!tn) {
            int s = x[0] - '0' + x[1] - '0';
            x[0] = s + '0';
            x.erase(x.begin() + 1);
        }

        cout << x << endl;
    }
}
