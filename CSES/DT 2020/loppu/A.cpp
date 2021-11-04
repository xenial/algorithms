#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

string solve(int n) {
    string s = "131517";
    while(s.size() < n) {
        s += "13151317";
    }
    return s.substr(0, n);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;
    cout << solve(n);
}