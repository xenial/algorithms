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
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

struct city {
    ll w;
    int n;
    bool c;
};

struct edge {
    ll w;
    int n;
};

struct cmp {
    bool operator()(city &v1, city &v2) {
        return v1.w > v2.w;
    }
};

int N, M;
vector<vector<edge>> adj;
ll ans[100005][2];
bool vis[100005];

int main() {
	set_io("");

    cin >> N >> M;
    adj.rsz(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
    }

    fill_n(&ans[0][0], 100005*2, LLONG_MAX);
    ans[1][0] = ans[1][1] = 0;
    priority_queue<city, vector<city>, cmp> q;
    q.push({0, 1, 0});

    while (!q.empty()) {
        city cc = q.top();
        q.pop();

        if (cc.w != ans[cc.n][cc.c]) continue;
        if (cc.n == N) break; 

        for (auto e : adj[cc.n]) {
            if (ans[e.n][cc.c] > cc.w + e.w) {
                ans[e.n][cc.c] = cc.w + e.w;
                q.push({ans[e.n][cc.c], e.n, cc.c});
            }

            if (!cc.c) {
                if (ans[e.n][1] > cc.w + e.w / 2) {
                    ans[e.n][1] = cc.w + e.w / 2;
                    q.push({ans[e.n][1], e.n, 1});
                }
            }
        }
    }

    cout << ans[N][1] << endl;
}
