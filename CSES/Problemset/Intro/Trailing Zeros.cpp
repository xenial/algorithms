#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll n) {
    ll i = 0, a = 0, b;

    while(++i) {
        ll c = (ll)pow(5.0f, (float)i);
        b = (ll)floor(n / (ll)pow(5.0f, (float)i));
        if (b == 0)
            break;
        a += b;
    }

    printf("%lld", a);
}

int main() {
    ll n;
    scanf("%lld", &n);
    solve(n);
}