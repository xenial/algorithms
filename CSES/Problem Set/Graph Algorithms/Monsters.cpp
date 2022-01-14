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

int n, m;
char grid[1005][1005];
vector<ii> exits;
ii player = {-1, -1};
ii parent[1005][1005];
int dx[]{-1, 0, 1, 0}, dy[]{0, -1, 0, 1};

bool bfs(ii s) {
    vector<vector<bool>> vis(m, vector<bool>(n));
    queue<ii> q;
    q.push(s);
    vis[s.fi][s.se] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        bool possible = false;
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] ||
                grid[nx][ny] == '#')
                continue;

            parent[nx][ny] = {cx, cy};

            if (grid[nx][ny] == 'A') possible = true;
            else if (grid[nx][ny] == 'M') return false;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }

        if (possible) return true;
    }

    return false;
}

char dir(ii s, ii t) {
    if (s.fi > t.fi) return 'L';
    if (s.fi < t.fi) return 'R';
    if (s.se > t.se) return 'U';
    if (s.se < t.se) return 'D';
    return '?';
}

int main() {
    set_io("");

    cin >> n >> m;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++) {
            cin >> grid[x][y];
            
            if (grid[x][y] == 'A') player = {x, y};

            if ((x == 0 || y == 0 || x == m - 1 || y == n - 1) &&
                grid[x][y] == '.')
                exits.pb({x, y});
        }

    bool surr = true, edge = player.fi == 0 || player.fi == m - 1 ||
                             player.se == 0 || player.se == n - 1;

    if (edge) {
        cout << "YES" << endl << 0 << endl;
        return 0;
    }

    for (int d = 0; d < 4; d++)
        if (grid[player.fi + dx[d]][player.se + dy[d]] != 'M') surr = false;

    if (player == ii(-1, -1) || surr) {
        cout << "NO" << endl;
        return 0;
    }

    for (auto exit : exits) {
        if (!bfs(exit)) continue;

        string path;
        while (exit != player) {
            path += dir(player, parent[player.fi][player.se]);
            player = parent[player.fi][player.se];
        }

        cout << "YES" << endl << path.sz() << endl << path << endl;
        return 0;
    }

    cout << "NO" << endl;
}
