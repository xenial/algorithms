#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> a) {
    sort(a.begin(), a.end());
    ll b = a[a.size() - 1];
    a.erase(a.begin() + a.size() - 1);
    ll sum = 0, avg;

    for (auto n : a) {
        sum += n;
    }

    avg = sum / a.size();

    return avg + b;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll t, t2, n;
    vector<ll> a;
    cin >> t;
    while (t--) {
        cin >> t2;
        while (t2--) {
            cin >> n;
            a.push_back(n);
        }
        cout << solve(a) << endl;
        a.clear();
    }
}