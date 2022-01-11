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

vector<vector<int>> roads;
vector<bool> found;
vector<int> ans;

void dfs(int n) {
    found[n] = true;
    for (auto road : roads[n]) {
        if (!found[road]) dfs(road);
    }
}

int main() {
    set_io("");
    int n, m; cin >> n >> m;

    roads.rsz(n); found.rsz(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        roads[a-1].pb(b-1);
        roads[b-1].pb(a-1);
    }
    
    for (int i = 0; i < n; i++) {
        if (!found[i]) {
            dfs(i);
            ans.pb(i);
        }
    }

    cout << ans.sz() - 1 << endl;
    for (int i = 0; i < ans.sz() - 1; i++) cout << ans[i] + 1 << " " << ans[i+1] + 1 << endl;
}