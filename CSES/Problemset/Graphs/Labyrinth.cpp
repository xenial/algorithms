#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
string dirs = "RDLU";

char Map[1001][1001];
bool visited[1001][1001] = {{false}};
int parent[1001][1001];
int depth[1001][1001];

int main() {
    set_io("");

    fill_n(&depth[0][0], 1001*1001, INT_MAX);

    int N, M; cin >> N >> M;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++) cin >> Map[x][y];

    pair<int,int> start, end;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++) {
            if (Map[x][y] == 'A') start = {x, y};
            if (Map[x][y] == 'B') end = {x, y};
        }

    queue<pair<int,int>> q;
    q.push(start);

    depth[start.fi][start.se] = 0;
    visited[start.fi][start.se] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= M) continue;
            if (ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || Map[nx][ny] == '#') continue;

            visited[nx][ny] = true;
            q.push({nx, ny});

            if (depth[nx][ny] > depth[x][y] + 1) {
                depth[nx][ny] = depth[x][y] + 1;
                parent[nx][ny] = (d + 2) % 4;
            }
        }
    }

    if (!visited[end.fi][end.se]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl << depth[end.fi][end.se] << endl;

    auto [x, y] = end;
    stack<char> ans;

    while (x != start.fi || y != start.se) {
        int d = parent[x][y];
        ans.push(dirs[d]);
        x += dx[d];
        y += dy[d];
    }

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }

    cout << endl;
}
