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

int dx[4] {-1, 0, 1, 0};
int dy[4] {0, -1, 0, 1};
char dir[4] {'R', 'D', 'L', 'U'};
char Map[1001][1001];
bool adj[1001][1001][4] = {{{false}}};
bool visited[1001][1001];
int depth[1001][1001];
int parent[1001][1001];

int main() {
    set_io("");

    int N, M; cin >> N >> M;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++) cin >> Map[x][y];

    pair<int,int> start = {-1, -1}, end = {-1, -1};
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++) {
            char cc = Map[x][y];
            if (cc == '#') continue;

            for (int d = 0; d < 4; d++) {
                char c = Map[x + dx[d]][y + dy[d]];
                if (c != '#') {
                    if (c == 'A' && start.fi == -1) 
                        start = {x + dx[d], y + dy[d]};
                    else if (c == 'B' && end.fi == -1) 
                        end = {x + dx[d], y + dy[d]};
                    adj[x][y][d] = true;
                    adj[x + dx[d]][y + dy[d]][(d + 2) % 4] = true;
                }
            }
        }

    queue<pair<int,int>> q;
    q.push(start);

    fill_n(&depth[0][0], 1001*1001, (int)INT_MAX);
    depth[start.fi][start.se] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            if (!adj[x][y][d]) continue;

            int nx = x + dx[d], ny = y + dy[d];

            if (depth[x][y] + 1 < depth[nx][y + dy[d]]) {
                depth[nx][ny] = depth[x][y] + 1;
                parent[nx][ny] = (d + 2) % 4;
            }

            if (visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    if (!visited[end.fi][end.se] || depth[end.fi][end.se] == 0) {
        cout << "NO";
        return 0;
    } else cout << "YES" << endl << depth[end.fi][end.se] << endl;

    int x = end.fi, y = end.se;
    stack<char> ans;
    while (x != start.fi || y != start.se) {
        int d = parent[x][y];

        ans.push(dir[d]);
        
        x = x + dx[d];
        y = y + dy[d];
    }

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
}
