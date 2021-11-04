#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<int> w, ll x) {
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == x)
            continue;
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll n, x;
    cin >> n, x;
    vector<int> w;

    while (n--) {
        int x;
        cin >> x;
        w.push_back(x);
    }

    cout << solve(w, x);
}