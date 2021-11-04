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

int solve(vector<pair<int,int>> times) {
    sort(all(times), cmp);

    int le = 0, ans = 0;
    for (int i = 0; i < times.sz(); i++) {
        if (le > times[i].fi) continue;
        ans++;
        le = times[i].se;
    }

    return ans;
}

int main() {
    set_io("");

    int n; cin >> n;
    vector<pair<int,int>> times;
    while (n--) {
        int a, b; cin >> a >> b;
        times.pb({a,b});
    }
    cout << solve(times);
}