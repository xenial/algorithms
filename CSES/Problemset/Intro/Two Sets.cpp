#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll n) {
    ll i, c[2] = {0,0}, s = n * (n + 1) / 2;
    vector<ll> a[2];

    if (s % 2 != 0) {
        printf("NO");
        return;
    } else {
        printf("YES");
    }

    for (i = n; i > 0; i--) {
        if (i + c[0] <= s / 2) {
            c[0] += i;
            a[0].push_back(i);
        } else if (i + c[1] <= s / 2) {
            c[1] += i;
            a[1].push_back(i);
        }
    }

    for (i = 0; i < 2; i++) {
        cout << endl << a[i].size() << endl;
        for (ll x : a[i]) {
            printf("%lld ", x);
        }
    }
}

int main() {
    ll n;
    scanf("%lld", &n);
    solve(n);
}