#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
//#define fstream

set<int> visited;

bool is_path(vector<vector<int>> adj, int n1, int n2) {
    visited.insert(n1);
    bool found = false;
    for (auto n : adj[n1]) {
        if (visited.count(n) > 0) continue;
        if (n == n2) return true;
        if (is_path(adj, n, n2)) found = true;
    }
    return found;
}

int solve(vector<vector<int>> adj) {
    for (int i = 1; i < adj.size(); i++) {
        bool valid = true;
        for (int j = 1; j < adj.size(); j++) {
            if (j == i) continue;
            visited = set<int>();
            if(!is_path(adj, j, i)) {
                valid = false;
                break;
            }
        }
        if (valid) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("factory.in"); 
	ofstream cout("factory.out"); 
    #endif

    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    while(--n) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << solve(adj);
}