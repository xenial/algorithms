#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a[], ll n) {
    ll c = 0;
    for (ll i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            c += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    return c;
}

int main() {
    ll n, i;
    scanf("%lld", &n);
    ll a[n];
    
    for (i = 0; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        a[i] = t;
    }

    printf("%lld", solve(a, n));
}