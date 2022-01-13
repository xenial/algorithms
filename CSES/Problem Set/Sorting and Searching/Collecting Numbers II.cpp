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

int pos[200005];

int main() {
	set_io("");

    int n, m; cin >> n >> m;

    vector<int> arr(n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i] = x;
        pos[x] = i;
        if (pos[x] < pos[x - 1] || (pos[x] > pos[x + 1] && pos[x + 1] != 0)) ans++;
    }

    while (m--) {
        int a, b; cin >> a >> b;
        int av = arr[a], bv = arr[b];

        int o = (int)(pos[av + 1] < pos[av] && pos[av + 1] != 0) +
                (int)(pos[av - 1] > pos[av]) +
                (int)(pos[bv + 1] < pos[bv] && pos[bv + 1] != 0) +
                (int)(pos[bv - 1] > pos[bv]);

        if (abs(av - bv) == 1 && pos[max(av, bv)] < pos[min(av, bv)]) o--;

        swap(pos[arr[a]], pos[arr[b]]);
        swap(arr[a], arr[b]);

        ans += (int)(pos[av + 1] < pos[av] && pos[av + 1] != 0) +
               (int)(pos[av - 1] > pos[av]) +
               (int)(pos[bv + 1] < pos[bv] && pos[bv + 1] != 0) +
               (int)(pos[bv - 1] > pos[bv]) - o;

        if (abs(av - bv) == 1 && pos[max(av, bv)] < pos[min(av, bv)]) ans--;

        cout << ans << endl;
    }
}
