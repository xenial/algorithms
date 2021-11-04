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

int k;
vector<int> ropes;

bool fits(double x) {
    int count = 0;
    for (auto rope : ropes) count += rope / x;
    return count >= k;
}

int main() {
    set_io("");

    int n; cin >> n >> k;
    while (n--) {
        int x; cin >> x;
        ropes.pb(x);
    }
    
    double l = 0, r = 100000000001 / k;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (fits(m)) l = m;
        else r = m;
    }
    cout << setprecision(10) << l;
}