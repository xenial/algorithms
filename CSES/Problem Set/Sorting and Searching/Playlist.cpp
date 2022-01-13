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

map<int, int> pos;

int main() {
	set_io("");

    int n; cin >> n;

    vector<int> playlist(n + 1);
    for (int i = 1; i <= n; i++) cin >> playlist[i];

    int l = 1, r = 1, ans = 1;
    while (r <= n) {
        int cid = playlist[r];

        if (pos[cid] >= l) l = pos[cid] + 1;
        else {
            pos[playlist[r]] = r;
            r++;
            ans = max(ans, r - l);
        }
    }

    cout << ans << endl;
}
