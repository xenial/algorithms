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

void solve(set<int> nums, vector<int> queries) {
    for (auto query : queries) {
        auto it = nums.find(query);
        if (it == nums.end()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

int main() {
    set_io("");

    int n, k; cin >> n >> k;
    set<int> nums;
    vector<int> queries;
    while (n--) {
        int x; cin >> x;
        nums.insert(x);
    }
    while (k--) {
        int x; cin >> x;
        queries.pb(x);
    }

    solve(nums, queries);
}