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

void solve(vector<pair<pair<int,int>,int>> times) {
    sort(all(times));
    vector<int> ans(times.sz()); ans[times[0].se] = 1;
    priority_queue<pair<int,int>> q; q.push({-times[0].fi.se, 1});
    int maxsz = 0;

    for (int i = 1; i < times.sz(); i++) {
        if (times[i].fi.fi <= abs(q.top().fi)) {
            int rn = q.top().se + 1;
            ans[times[i].se] = rn;
            q.push({-times[i].fi.se, rn});
        } else {
            int rn = q.top().se;
            ans[times[i].se] = rn;
            q.pop();
            q.push({-times[i].fi.se, rn});
        }
        maxsz = max(maxsz, (int)q.sz());
    }

    cout << maxsz << endl;
    for (auto a : ans) cout << a << " ";
}

int main() {
    set_io("");

    int n; cin >> n;
    vector<pair<pair<int,int>,int>> times;
    for (int i = 0; i < n; i++) {
        int arr, dep; cin >> arr >> dep;
        times.pb({{arr, dep}, i});
    }
    solve(times);
}