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

int grid[2000][2000];
int N, M;

void fold(int pos, char dir) {
    if (dir == 'x') {
        for (int y = 0; y < M; y++)
            for (int x = pos + 1; x < N; x++) {
                int diff = x - pos;
                if (pos - diff >= 0) grid[pos - diff][y] |= grid[x][y];
            }
        
        N = pos;
    } else {
        for (int y = pos + 1; y < M; y++)
            for (int x = 0; x < N; x++) {
                int diff = y - pos;
                if (pos - diff >= 0) grid[x][pos - diff] |= grid[x][y];
            }

        M = pos;
    }
}

int main() {
    set_io("");

    N = M = 0;
    for (int i = 0; i < 796; i++) {
        int x, y; cin >> x >> y;
        grid[x][y] = true;
        N = max(N, x) + 1;
        M = max(M, y) + 1;
    }

    char dir; cin >> dir;
    int pos; cin >> pos;
    fold(pos, dir);

    int ans = 0;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            if (grid[x][y]) ans++;

    cout << ans << endl;
}
