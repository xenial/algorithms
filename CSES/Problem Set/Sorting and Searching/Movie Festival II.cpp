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

bool cmp(pair<int,int> v1, pair<int,int> v2) {
    return v1.se < v2.se;
}

int solve(vector<pair<int,int>> times, int k) {
    multiset<int> ends;
    sort(all(times), cmp);
    for (int i = 0; i < k; i++) ends.insert(0);

    int ans = 0;
    for (int i = 0; i < times.sz(); i++) {
        auto it = ends.lower_bound(-times[i].fi);
        if (it == ends.end()) continue;

        ends.erase(it);
        ends.insert(-times[i].se);
        ans++;
    }

    return ans;
}

int main() {
    set_io("");

    vector<pair<int,int>> times;
    int n, k; cin >> n >> k;
    while (n--) {
        int s, e; cin >> s >> e;
        times.pb({s, e});
    }
    cout << solve(times, k);
}