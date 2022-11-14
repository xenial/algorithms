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

int N;

int main() {
	set_io("");

    cin >> N;
    int map[N][N];
    ll dp[N][N];
    fill_n(&dp[0][0], N*N, 1);
    vector<pair<int, ii>> s;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> map[j][i];
            s.pb(make_pair(map[j][i], ii(j, i)));
        }
    
    sort(all(s));

    int h = s[0].fi, i = 1;
    for (auto &n : s) {
        int c = n.fi, cx = n.se.fi, cy = n.se.se;

        if (h < c) {
            i++;
            h = c;
        }

        n.fi = i;
        map[cx][cy] = i;
    }
    
    vector<vector<ii>> xp(N), yp(N);
    ll dpx[N], dpy[N];
    fill_n(&dpx[0], N, 0);
    fill_n(&dpy[0], N, 0);

    ll ans = 0;
    for (auto n : s) {
        int cx = n.se.fi, cy = n.se.se, cw = n.fi;
        ll cp = 1;

        for (int i = 0; i < xp[cx].sz(); i++) {
            int x = xp[cx][i].fi, y = xp[cx][i].se;
            if (cw <= map[x][y]) break;

            dpx[cx] = (dpx[cx] + dp[x][y]) % 1000000007;

            xp[cx].erase(xp[cx].begin() + i);
            i--;
        }

        cp = (cp + dpx[cx]) % 1000000007;

        for (int i = 0; i < yp[cy].sz(); i++) {
            int x = yp[cy][i].fi, y = yp[cy][i].se;
            if (cw <= map[x][y]) break;

            dpy[cy] = (dpy[cy] + dp[x][y]) % 1000000007;

            yp[cy].erase(yp[cy].begin() + i);
            i--;
        }

        cp = (cp + dpy[cy]) % 1000000007;
        ans = (ans + cp) % 1000000007;
        dp[cx][cy] = cp;
        xp[cx].pb(ii(cx, cy));
        yp[cy].pb(ii(cx, cy));
    }

    cout << ans << endl;
}
