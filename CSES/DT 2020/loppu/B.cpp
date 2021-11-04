#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<vector<int>> paths_to(vector<vector<int>> adj, int x, int y) {
    
}

int solve(vector<vector<int>> adj, int x, int y) {
    return paths_to(adj, set<int>(), 0, x, y);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, x, y; cin >> n >> x >> y;
    vector<vector<int>> adj(n + 1);
    while(--n) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    cout << solve(adj, x, y);
}