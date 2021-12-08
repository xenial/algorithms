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

string in[200][10], out[200][4];

int main() {
    set_io("");

    int ans = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 10; j++) cin >> in[i][j];
        for (int j = 0; j < 4; j++) {
            string x; cin >> x;
            int s = x.sz();
            if (s == 2 || s == 3 || s == 4 || s == 7) ans++;
        }
    }
    cout << ans << endl;
}
