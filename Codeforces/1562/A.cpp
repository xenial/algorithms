#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int solve(int l, int r) {
    int a = r;
    int b = floor(a / 2) + 1;
    if (b < l) b += abs(l - b);
    return a % b;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}