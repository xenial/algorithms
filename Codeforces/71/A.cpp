#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    if (s.size() <= 10)
        return s;

    return s.at(0) + to_string(s.size() - 2) + s.at(s.size() - 1);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        string a;
        cin >> a;
        cout << solve(a) << endl;
    }
}