#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

bool sorted(vector<int> perm) {
    for (int i = 1; i < perm.size(); i++) {
        if (perm[i - 1] > perm[i]) {
            return false;
        }
    }

    return true;
}

vector<int> helper(vector<int> perm, int i) {
    if (perm[i - 1] > perm[i]) {
        swap(perm[i], perm[i - 1]);
    }
    return perm;
}

int solve(vector<int> perm) {
    if (sorted(perm))
        return 0;
        
    for (int i = 1;; i++) {
        if (i % 2 != 0) {
            for (int j = 1; j <= perm.size() - 2; j += 2) {
                perm = helper(perm, j);
            }
        } else {
            for (int j = 2; j <= perm.size() - 1; j += 2) {
                perm = helper(perm, j);
            }
        }
        if (sorted(perm))
            return i;
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> perm;
        while (n--) {
            int x; cin >> x;
            perm.push_back(x);
        }
        cout << solve(perm) << endl;
    }
}