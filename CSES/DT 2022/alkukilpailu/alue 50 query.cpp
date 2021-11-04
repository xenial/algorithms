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

typedef pair<int, int> point;

int ans[50][50] = {0};
vector<set<int>> adj(2500);

int main() {
    set_io("");
    
    {
        ifstream cin("C:/Users/maste/OneDrive/Programming/learning/alue50.in");
        for (int i = 0; i < 100; i++) {
            int l; cin >> l;
            for (int j = 1; j < 100; j++) {
                int x; cin >> x;
                adj[l-1].insert(x-1);
                adj[x-1].insert(l-1);
                l = x;
            }
        }
    }

    while (true) {
        int n; cin >> n;
        int ctr = 1;
        for (auto node : adj[n - 1]) {
            cout << ctr << ": " << node + 1 << endl;
            ctr++;
        }
    }
}