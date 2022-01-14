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

ll n; 

bool valid(ll q) {
    ll leq = 0;
    for (ll y = 1; y <= n; y++) {
        leq += min(n, q / y);
    }
    
    ll hw = (n * n) / 2 + 1;
    return leq >= hw;
}

int main() {
	set_io("");

    cin >> n;

    ll l = 1, r = n * n;
    while (l + 1 < r) {
        ll m = (l + r) / 2;

        if (valid(m)) r = m;
        else l = m;
    }

    cout << r << endl;
}
