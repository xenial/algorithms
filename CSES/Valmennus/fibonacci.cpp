#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    
        
    ll b, p1 = 0, p2 = 1, mod = 1000000000 + 7;
    vector<ll> period;
    for (ll i = 0; i < n; i++) {
        p1 = p1 % mod;
        p2 = p2 % mod;

        if (i != 0 && p1 == 0 && p2 == 1)
            break;
            
        period.push_back(p1);


        b = p1 + p2;
        p1 = p2;
        p2 = b;
    }

    cout << period.size();

    return b;
}

int main() {
    ll n;
    scanf("%lld", &n);
    //printf("%lld", solve(n));
    solve(n);
}