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

int N, M, id[100005];
vvi adj(100005);

int main() {
	set_io("");

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        id[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (id[i] == 0) q.push(i);

    vector<int> ans;
    while (!q.empty()) {
        int cn = q.front();
        q.pop();
        ans.pb(cn);

        for (auto n : adj[cn]) {
            id[n]--;
            if (id[n] == 0) q.push(n);
        }
    }

    if (ans.sz() != N) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (auto n : ans) cout << n << " ";
    cout << endl;
}
