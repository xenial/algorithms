#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(string s) {
    ll c[2] = {1,1};
    for (ll i = 1; i < s.size(); i++) {
        if (s.at(i) == s.at(i - 1))
            c[0]++;
        else {
            c[1] = max<ll>(c[0], c[1]);
            c[0] = 1;
        }
    }
    return max<ll>(c[0], c[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    printf("%lld", solve(s));
}