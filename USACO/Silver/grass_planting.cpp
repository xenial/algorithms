#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

int solve(vector<vector<int>> adj) {
    int max_adj = 0;
    for (auto n : adj) {
        max_adj = max(max_adj, (int)n.size());
    }
    return max_adj + 1;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("planting.in"); 
	ofstream cout("planting.out"); 
    #endif

    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    while(--n) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << solve(adj);
}