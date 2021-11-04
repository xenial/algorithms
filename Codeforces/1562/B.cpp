#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<int> solve(string b) {
    int mchain = 0, zchain = 0;
    for (auto c : b) {
        if (c == '0') zchain++;
        else mchain = max(mchain, zchain);
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string b; cin >> b;
        vector<int> ranges = solve(b);
        for (auto r : ranges) cout << r << " ";
        cout << endl;
    }
}