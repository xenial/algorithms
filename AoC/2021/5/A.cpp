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

int grid[1005][1005];

int main() {
    set_io("");

    for (int i = 0; i < 500; i++) {
        ii x, y;
        cin >> x.fi >> y.fi >> x.se >> y.se;

        if (x.fi != x.se && y.fi != y.se) continue;

        bool dir = 0; // 0 = x, 1 = y
        if (x.fi == x.se) dir = 1;
        if (x.fi > x.se) swap(x.fi, x.se);
        if (y.fi > y.se) swap(y.fi, y.se);

        if (!dir) 
            for (int j = x.fi; j <= x.se; j++) grid[j][y.fi]++;
        else
            for (int j = y.fi; j <= y.se; j++) grid[x.fi][j]++;
    }

    int ans = 0;
    for (int i = 0; i < 1001; i++) 
        for (int j = 0; j < 1001; j++) 
            if (grid[i][j] > 1) ans++;

    cout << ans << endl;
}
