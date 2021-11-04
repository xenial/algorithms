#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    ll f = 0, i = 1, c;
    do {
        c = (ll)floor(n / pow(5, i));
        if (!c)
            break;
        f += c;
    } while(i++);

    return f;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll n;
    cin >> n;
    cout << solve(n);
}