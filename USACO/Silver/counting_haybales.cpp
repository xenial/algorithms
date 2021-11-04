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
    set_io("haybales");

    int n, q; cin >> n >> q;
    vector<int> bales(n);
    for (int i = 0; i < n; i++) cin >> bales[i];
    sort(all(bales));

    while (q--) {
        int a, b; cin >> a >> b;
        cout << upper_bound(all(bales), b) - lower_bound(all(bales), a) << endl;
    }
}