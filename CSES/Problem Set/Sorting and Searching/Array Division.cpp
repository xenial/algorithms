#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int n, k;
vector<int> arr;

bool valid(ll x) {
    ll subs = 1, sum = 0;
    for (auto n : arr) {
        sum += n;
        if (sum > x) {
            subs++;
            sum = n;
        }
        if (subs > k) break;
    }
    return subs <= k;
}

int main() {
    set_io("");

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll l = *max_element(all(arr)) - 1, r = 1e15;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (valid(m)) r = m;
        else l = m;
    }
    cout << r;
}