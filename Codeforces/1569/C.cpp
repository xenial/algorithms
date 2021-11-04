#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

int mod = 998244353;

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int solve(vector<int> problems) {
    vector<int> perm;
    for (int i = 0; i < problems.size(); i++) perm.pb(i);

    sort(all(problems), greater<int>());
    int ans = 0;
    do {
        if (problems[0] - problems[perm[0]] > 1 || problems[0] - problems[perm[0]] < 0) break;
        int diff = -1;
        for (int i = 1; i < perm.size(); i++) {
            diff = problems[perm[0]] - problems[perm[i]];
            if (diff == 1 || diff == 0) break;
        }
        if (diff > 1 || diff < 0) return ans;
        ans++;
        ans %= mod; 
    } while(next_permutation(all(perm)));
    return ans;
}

int main() {
    set_io("");

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> problems;
        while (n--) {
            int p; cin >> p;
            problems.pb(p);
        }
        cout << solve(problems) << endl;
    }
}