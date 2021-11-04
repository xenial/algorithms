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

int n, k;
vector<int> arr;

bool possible(int x) {
    ll m = arr.sz() / 2, ops = 0;
    for (int i = m; i < arr.sz(); i++) {
        if (arr[i] < x) ops += x - arr[i];
    }
    return ops <= k;
}

int main() {
    set_io("");

    cin >> n >> k;
    if (n == 1) {
        int x; cin >> x;
        cout << x + k;
        return 0;
    }
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(all(arr));

    ll l = arr[arr.sz() / 2], r = arr[arr.sz() / 2] + k + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (possible(m)) l = m;
        else r = m;
    }
    cout << l;
}