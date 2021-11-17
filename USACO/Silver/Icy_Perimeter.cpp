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

char Map[1000][1000];
bool visited[1000][1000];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int N;

ii ff(int x, int y, int a = 0, int p = 0) {
    visited[x][y] = true;
    a++;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || Map[nx][ny] == '.') {
            p++;
            continue;
        } 

        if (visited[nx][ny]) continue;

        tie(a, p) = ff(nx, ny, a, p);
    }

    return {a, p};
}

int main() {
    set_io("perimeter");

    cin >> N;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++) {
            cin >> Map[x][y];
        }

    ii bb = {0, 1e9};
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++) {
            if (Map[x][y] != '.' && !visited[x][y]) {
                ii b = ff(x, y);
                if (b.fi > bb.fi) bb = b;
                else if (b.fi == bb.fi && b.se < bb.se) bb = b;
            }
        }

    cout << bb.fi << " " << bb.se << endl;
}
