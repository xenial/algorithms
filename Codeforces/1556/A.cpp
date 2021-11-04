#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int solve(int a, int b) {
    if ((a + b) % 2 != 0) return -1;
    int avg = (a + b) / 2;
    if (a == 0 && b == 0) return 0;
    if (a == avg) return 1;
    return 2;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}