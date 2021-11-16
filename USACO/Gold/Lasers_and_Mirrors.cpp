#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int, int>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ii pos[100002];
int depth[100002];
unordered_map<int, set<int>> a[2];

int main() {
    set_io("lasers");

    fill_n(&depth[0], 100002, INT_MAX);
    depth[0] = -1;

    int N;
    cin >> N >> pos[0].fi >> pos[0].se >> pos[N + 1].fi >> pos[N + 1].se;
    a[0][pos[N + 1].fi].insert(N + 1);
    a[1][pos[N + 1].se].insert(N + 1);

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        a[0][x].insert(i);
        a[1][y].insert(i);
        pos[i] = {x, y};
    }

    queue<pair<int,bool>> q; // beam dir, 0 = h, 1 = v
    q.push({0, 0});
    q.push({0, 1});

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        auto [x, y] = pos[c.fi];
        bool dir = !c.se;
        int axis = dir ? y : x;

        for (auto n : a[dir][axis]) {
            if (depth[n] == INT_MAX) {
                depth[n] = depth[c.fi] + 1;
                q.push({n, dir});
            }
        }
    }

    cout << (depth[N + 1] == INT_MAX ? -1 : depth[N + 1]) << endl;
}
