#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(vector<int> n) {
    int sum = 0;
    for (auto i : n) {
        sum += i;
    }
    
    return (sum >= 2 ? true : false);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t, s, n = 0;
    cin >> t;

    while (t--) {
        vector<int> a;
        for (int i = 0; i < 3; i++) {
            cin >> s;
            a.push_back(s);
        }
        if (solve(a))
            n++;
    }

    cout << n;
}