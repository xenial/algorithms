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

bool visited[1000][1000];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int N, M;

void ff(int x, int y) {
    visited[x][y] = true;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        
        if (ny < 0 || ny >= N) continue;
        if (nx < 0 || nx >= M) continue;
        if (visited[nx][ny]) continue;

        ff(nx, ny);
    }
}

int main() {
    set_io("");

    cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            char c; cin >> c;
            visited[x][y] = c == '#';
        }
    }

    int ans = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (visited[x][y]) continue;

            ff(x, y);
            ans++;
        }
    }

    cout << ans << endl;
}
