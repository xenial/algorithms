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

int solve(vector<int> algos, int x) {
    sort(all(algos));
    int count = 0, i = 0;
    while (count + algos[i] <= x && i < algos.sz()) {
        count += algos[i];
        i++;
    }
    return i;
}

int main() {
    set_io("");

    int n, x; cin >> n >> x;
    vector<int> algos;
    while (n--) {
        int y; cin >> y;
        algos.pb(y);
    }
    cout << solve(algos, x);
}