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
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

vector<pair<ii, int>> ranges;
bool ans[200005][2];

bool cmp(pair<ii, int> &v1, pair<ii, int> &v2) {
    if (v1.fi.fi == v2.fi.fi) return v1.fi.se > v2.fi.se;
    return v1.fi.fi < v2.fi.fi;
}

int main() {
	set_io("");

    int N; cin >> N;

    ranges.rsz(N);
    int i = 0;
    for (auto &r : ranges) {
        cin >> r.fi.fi >> r.fi.se;
        r.se = i;
        i++;
    }
    sort(all(ranges), cmp);

    int MR = 0, mR = 2e9;
    for (int i = N - 1; i >= 0; i--) {
        if (mR <= ranges[i].fi.se) ans[ranges[i].se][0] = true;
        mR = min(mR, ranges[i].fi.se);
    }
    for (int i = 0; i < N; i++) {
        if (MR >= ranges[i].fi.se) ans[ranges[i].se][1] = true;
        MR = max(MR, ranges[i].fi.se);
    }

    for (int i = 0; i < N; i++) cout << ans[i][0] << " ";
    cout << endl;
    for (int i = 0; i < N; i++) cout << ans[i][1] << " ";
}
