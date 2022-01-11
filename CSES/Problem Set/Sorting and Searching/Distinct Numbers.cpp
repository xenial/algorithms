#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> a) {
    set<int> r;
    for (auto n : a)
        r.insert(n);
    return r.size();
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;
    vector<int> a;
    while (n--) {
        int x; cin >> x;
        a.push_back(x);
    }
    cout << solve(a);
}