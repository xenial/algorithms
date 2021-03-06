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

    int n; cin >> n;

    vector<ii> ops(n * 2);

    int i = 0;
    for (auto &o : ops) {
        cin >> o.fi;
        o.se = i % 2 ? -1 : 1;
        i++;
    }

    sort(all(ops));

    int buf, ans;
    buf = ans = 0;

    for (auto o : ops) {
        buf += o.se;
        ans = max(ans, buf);;
    }

    cout << ans << endl;
}
