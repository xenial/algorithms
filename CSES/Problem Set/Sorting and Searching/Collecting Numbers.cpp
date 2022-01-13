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

bool seen[200005];

int main() {
	set_io("");

    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        if (!seen[x - 1]) ans++;

        seen[x] = true;
    }

    cout << ans << endl;
}
