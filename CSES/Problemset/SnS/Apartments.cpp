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

int solve(vector<int> ds, vector<int> as, int k) {
    sort(all(ds));
    sort(all(as));

    int i = 0, j = 0, r = 0;
    while (i < as.sz() && j < ds.sz()) {
        if (as[i] < ds[j] - k) i++;
        else if (ds[j] + k < as[i]) j++;
        else if (ds[j] - k <= as[i] && as[i] <= ds[j] + k) {
            i++; j++; r++;
        }
    }
    return r;
}

int main() {
    set_io("");
    int n, m, k; cin >> n >> m >> k;
    vector<int> ds(n), as(m);
    for (int i = 0; i < n; i++) cin >> ds[i];
    for (int i = 0; i < m; i++) cin >> as[i];

    cout << solve(ds, as, k);
}