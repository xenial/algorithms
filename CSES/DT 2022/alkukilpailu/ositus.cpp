#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

ll mod = 1e9+7;

ll modpow(ll x, ll ex)
{
    ll ans = 1;
    x = x % mod;
  
    if (x == 0) return 0; 
 
    while (ex > 0) {
        if (ex & 1) ans = (ans * x) % mod;
        ex = ex>>1;
        x = (x*x) % mod;
    }
    return ans;
}

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

    string s; cin >> s;
    vector<int> open(26, -1);
    ll ans = 0;

    for (int i = 0; i < s.sz(); i++) {
        
    }

    cout << ans << endl;
}