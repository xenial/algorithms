#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ll solve(vector<pair<int,int>> tasks) {
    sort(all(tasks));
    ll ans = 0, ct = 0;
    for (auto task : tasks) {
        ct += task.fi;
        ans += task.se - ct;
    }
    return ans;
}

int main() {
    set_io("");

    int n; cin >> n;
    vector<pair<int,int>> tasks;
    while (n--) {
        int a, b; cin >> a >> b;
        tasks.pb({a,b});
    }
    cout << solve(tasks);
}