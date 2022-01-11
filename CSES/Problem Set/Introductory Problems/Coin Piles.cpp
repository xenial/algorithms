#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(ll a, ll b) {
    if (a < 0 || b < 0)
        return false;
    if (a == 0 && b == 0)
        return true;
    if ((a == 0 && b != 0) || (a != 0 && b == 0))
        return false;
    if ((a > 2 * b) || (b > 2 * a))
        return false;
    if ((a + b) % 3 == 0)
        return true;
        
    return false;
}

int main() {
    ll t, a, b;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &a);
        scanf("%lld", &b);
        printf("%s\n", solve(a, b) ? "YES" : "NO");
    }
}