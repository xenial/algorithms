#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll s) {
    ll ns = n * (n + 1) / 2;
    return ns - s;
}

int main() {
    ll t, c, n, s = 0;
    scanf("%lld", &t);
    c = t;
    while(--c) {
        scanf("%lld", &n);
        s += n;
    }
    printf("%lld", solve(t, s));
}