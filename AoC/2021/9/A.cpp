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

int in[100][100];

int main() {
    set_io("");

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            char x; cin >> x;
            in[j][i] = x - '0';
        }

    int dx[]{-1, 0, 1, 0}, dy[]{0, -1, 0, 1};

    int ans = 0;
    for (int y = 0; y < 100; y++) 
        for (int x = 0; x < 100; x++) {
            bool lp = true;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= 100) continue;
                if (ny < 0 || ny >= 100) continue;

                if (in[nx][ny] <= in[x][y]) lp = false;
            }
            if (lp) ans += in[x][y] + 1;
        }

    cout << ans << endl;
}
