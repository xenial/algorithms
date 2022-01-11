#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pwr(ll n, ll e) {
    ll t = n;
    while(--e)
        n = (n * t) % ((ll)pow(10, 9) + 7);
    return n;
}

void solve(ll n) {

    printf("%lld", pwr(2, n));
}

int main() {
    ll n;
    scanf("%lld", &n);
    solve(n);
}