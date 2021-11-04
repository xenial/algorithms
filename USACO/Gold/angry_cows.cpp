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

vector<int> bales;

bool valid(double pwr) {
    bool ans;
    for (int i = 0; i < bales.sz(); i++) {
        ans = true;
        double rad = pwr;
        vector<int>::iterator l = bales.begin() + i;
        vector<int>::reverse_iterator r = bales.rend() + i;
        for (; rad > 0; rad--) {
            l = lower_bound(all(bales), *l - rad);
            r = lower_bound(bales.rbegin(), bales.rend(), *r + rad);
        }
    }
    return ans;
}

int main() {
    set_io("");

    int n; cin >> n;
    bales.rsz(n);
    for (int i = 0; i < n; i++) cin >> bales[i];
    sort(all(bales));

    double l = 0, r = 2e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (valid(m)) r = m;
        else l = m;
    }
    cout << setprecision(1) << r;
}