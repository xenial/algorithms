#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> a) {
    int res = -1;

    for (auto n : a) {
        res &= n;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll l, l2;
    cin >> l;

    while(l--) {
        vector<ll> a;
        cin >> l2;
        ll n;
        while (l2--) {
            cin >> n;
            a.push_back(n);
        }
        cout << solve(a) << endl;
    }
}