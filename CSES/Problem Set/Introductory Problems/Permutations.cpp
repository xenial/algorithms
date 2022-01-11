#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll n) {
    ll b, i;
    vector<ll> a;
    if (n < 4 && n != 1) {
        printf("NO SOLUTION");
        return;
    }

    for (i = 0; i < n; i++) {
        b = i + 1;
        if (b % 2 == 0) {
            a.push_back(b);
        }
    }

    for (i = 0; i < n; i++) {
        b = i + 1;
        if (b % 2 != 0) {
            a.push_back(b);
        }
    }

    for (ll n : a) {
        printf("%lld ", n);
    }
}

int main() {
    ll n;
    scanf("%lld", &n);
    solve(n);
}