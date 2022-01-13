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

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int main() {
	set_io("");

    int n, m; cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        tickets.insert(-t);
    }
    
    while (m--) {
        int o; cin >> o;

        auto it = tickets.lower_bound(-o);
        if (it != tickets.end()) {
            cout << -*it << endl;
            tickets.erase(it);
        } else cout << -1 << endl;
    }
}
