#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n) {
    vector<int> sq;

    for (int i = 1; i < n * 2; i++) {
        int l = floor(log10(i));
        int ld = i % 10;

        if (ld == 3)
            continue;
        else if ((i) % 3 == 0) {
            continue;
        }
        else
            sq.push_back(i);
    }

    return sq.at(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}