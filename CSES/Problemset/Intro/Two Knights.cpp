#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll solve(ll n) {
    ll c, t;
    c = ((n * n) * (n * n - 1)) / 2;
    t = 2 * 2 * ((n - 1) * (n - 2)); // 2x3 square = 2 threats. n-1 squares per row, n-2 squares per column. same num of 3x2 squares bcs symmetry
    return c - t;
}
 
int main() {
    ll n, i;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        printf("%lld\n", solve(i));
    }
}