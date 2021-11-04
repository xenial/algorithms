#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll) {
    ll b = 0, sb = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b) {
            b = a[i];
            continue;
        }
        
        if (a[i] < b) {
            sb = a[i];
        }
    }

    return b * sb;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}