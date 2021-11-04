#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    return (n * n) * (n * n - 1) / 2 - (n - 2) * (n - 1) * 2 * 2;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll n;
    cin >> n;
    cout << solve(n);
}