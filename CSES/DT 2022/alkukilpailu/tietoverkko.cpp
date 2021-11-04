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
 
int LOG = 0;
const int MX = 200001;
 
vector<pair<int,int>> adj[MX];
int depth[MX];
int anc[MX][14], bw[MX][14] = {INT_MAX};
 
void dfs() {
    int l = -1;
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
        auto a = s.top();
        s.pop();
 
        for (int i = 1; i < LOG; i++) {
            if (anc[a][i - 1] != -1) {
                anc[a][i] = anc[anc[a][i - 1]][i - 1];
                bw[a][i] = min(bw[a][i - 1], bw[anc[a][i - 1]][i - 1]);
            }
        }
 
        for (auto n : adj[a]) {
            if (n.fi == l) continue;
            anc[n.fi][0] = a;
            bw[n.fi][0] = n.se;
            depth[n.fi] = depth[a] + 1;
            s.push(n.fi);
        }
    }
}
 
int getbw(int a, int b) {
    int ans = INT_MAX;
 
    if (depth[a] > depth[b]) swap(a, b);
 
    if (depth[a] < depth[b]) {
        int diff = depth[b] - depth[a];
 
        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i)) {
                if (bw[b][i]) ans = min(ans, bw[b][i]);
                b = anc[b][i];
            }
        }
    }
 
    if (a == b) return ans;
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (anc[a][i] != anc[b][i]) {
            ans = min({ans, bw[a][i], bw[b][i]});
            a = anc[a][i];
            b = anc[b][i];
        }
    }
 
    return min({ans, bw[a][0], bw[b][0]});
}
 
int main() {
    set_io();
    //set_io("C:\\Users\\maste\\OneDrive\\Programming\\learning\\tverkko");
 
    int n; cin >> n;
 
    for (int i = 0; i < n - 1; i++) {
        int a, b, x; cin >> a >> b >> x;
        adj[a-1].pb({b-1, x});
    }
 
    while (1 << (LOG + 1) <= n) LOG++;
 
    dfs();
 
    ll ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            ans += getbw(i, j);
 
    cout << ans << endl;
}