#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> m(1000, 0);

ll solve(int n) {
    if (n < 3)
        return 1;
    if (m.at(n - 1)) {
        return m.at(n - 1);
    }

    ll a = solve(n - 1) + solve(n - 2);
    m.at(n - 1) = a;
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", solve(n));
}