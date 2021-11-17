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

int main() {
    set_io("");

    int n; cin >> n;
    vector<int> a(n);
    while (n--) {
        cin >> a[n];
    }
    sort(all(a));

    int k; cin >> k;
    while (k--) {
        int x, y; cin >> x >> y;
        pair<int,int> ans;
        int l = -1, r = a.sz();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[m] < x) l = m;
            else r = m;
        }
        ans.fi = r;
        l = -1; r = a.sz();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[m] <= y) l = m;
            else r = m;
        }
        ans.se = l;
        cout << ans.se - ans.fi + 1 << " ";
    }
}