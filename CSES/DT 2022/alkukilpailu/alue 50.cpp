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

typedef pair<int, int> point;

int ans[50][50] = {0};
vector<set<int>> adj(2500);
int paths[100][100];
int parent[2500];

vector<int> get_adj_vals(point coord) {
    vector<int> res;

    int x = coord.fi;
    int y = coord.se;

    if (ans[x + 1][y] != 0) res.pb(ans[x + 1][y]);
    if (ans[x - 1][y] != 0) res.pb(ans[x - 1][y]);
    if (ans[x][y + 1] != 0) res.pb(ans[x][y + 1]);
    if (ans[x][y - 1] != 0) res.pb(ans[x][y - 1]);

    return res;
}

vector<point> get_adj_coords(point coord) {
    vector<point> res;

    int x = coord.fi;
    int y = coord.se;

    res.pb({x + 1, y});
    res.pb({x - 1, y});
    res.pb({x, y + 1});
    res.pb({x, y - 1});

    return res;
}

int main() {
    set_io("C:/Users/maste/OneDrive/Programming/learning/alue50");

    for (int i = 0; i < 100; i++) {
        int l; cin >> l;
        paths[i][0] = l;
        for (int j = 1; j < 100; j++) {
            int x; cin >> x;
            adj[l-1].insert(x-1);
            adj[x-1].insert(l-1);
            paths[i][j] = x;
            l = x;
        }
    }

    ans[25][25] = paths[0][0];
    point curpos = {25, 25};
    for (int i = 0 ; i < 3; i++) {

    }
}