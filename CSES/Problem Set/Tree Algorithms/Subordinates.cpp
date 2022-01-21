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

int N;
int sub[200005];
vvi adj;

void dfs(int n, int p) {
    sub[n] = 1;

    for (auto a : adj[n]) {
        if (a == p) continue;
        dfs(a, n);
        sub[n] += sub[a];
    }
}

int main() {
	set_io("");

    cin >> N;
    adj.rsz(N + 1);

    for (int i = 2; i <= N; i++) {
        int x; cin >> x;
        adj[x].pb(i);
    }

    dfs(1, 0);
    for (int i = 1; i <= N; i++) cout << sub[i] - 1 << " ";
    cout << endl;
}
