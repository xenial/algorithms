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

int N, M;
vvi adj;
bool vis[100005], rs[100005];
stack<int> s;
int sn;

bool dfs(int n) {
    vis[n] = true;
    s.push(n);
    rs[n] = true;

    for (auto a : adj[n]) {
        if (vis[a]) {
            if (rs[a]) {
                sn = a;
                return true;
            }
            else continue;
        }

        if (dfs(a)) return true;
    }

    rs[n] = false;
    s.pop();
    return false;
}

int main() {
	set_io("");

    cin >> N >> M;
    adj.rsz(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;

        if (dfs(i)) {
            vi ans(1, sn);
            while (s.top() != sn) {
                ans.pb(s.top());
                s.pop();
            }

            ans.pb(sn);
            reverse(all(ans));

            cout << ans.sz() << endl;
            for (auto &n : ans) cout << n << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
