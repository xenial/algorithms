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

int dx[]{-1, -1, 0, 1, 1, 1, 0, -1}, dy[]{0, -1, -1, -1, 0, 1, 1, 1};
int grid[10][10];
bool flashed[10][10];

void f(int x, int y) {
    if (grid[x][y] < 10 || flashed[x][y]) return;
    grid[x][y] = 0;
    flashed[x][y] = true;

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx > 9) continue;
        if (ny < 0 || ny > 9) continue;

        if (!flashed[nx][ny]) {
            grid[nx][ny]++;
            f(nx, ny);
        } 
    }
}

int main() {
	set_io("");

    for (int y = 0; y < 10; y++) 
        for (int x = 0; x < 10; x++) {
            char c; cin >> c;
            grid[x][y] = c - '0';
        }

    int ans;
    for (int i = 0; true; i++) {
        memset(&flashed, 0, 100);
        for (int y = 0; y < 10; y++)
            for (int x = 0; x < 10; x++) 
                grid[x][y]++;

        for(int y = 0; y < 10; y++) 
            for (int x = 0; x < 10; x++)
                f(x, y);
        
        bool af = true;
        for(int y = 0; y < 10; y++) 
            for (int x = 0; x < 10; x++)
                if (!flashed[x][y]) af = false;

        if (af) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
}
