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
bool vis[100][100];
int cs = 0;
int dx[]{-1, 0, 1, 0}, dy[]{0, -1, 0, 1};

void ff(int x, int y) {
    if (x < 0 || x >= 100) return;
    if (y < 0 || y >= 100) return;
    if (in[x][y] == 9) return;
    if (vis[x][y]) return;
    vis[x][y] = true;
    cs++;
    for (int i = 0; i < 4; i++) ff(x + dx[i], y + dy[i]);
}

int main() {
    set_io("");

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            char x; cin >> x;
            in[j][i] = x - '0';
        }

    vector<int> bs;
    for (int y = 0; y < 100; y++) 
        for (int x = 0; x < 100; x++) {
            if (!vis[x][y]) {
                ff(x, y);
                bs.pb(cs);
                cs = 0;
            }
        }
    
    sort(all(bs), greater<int>());
    cout << bs[0] * bs[1] * bs[2] << endl;
}
