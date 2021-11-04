#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int solve(vector<int> arr, int t) {
    vector<int> pf(arr.size() + 1);
    for (int i = 1; i <= arr.size(); i++) {
        pf[i] = arr[i - 1];
        pf[i] += pf[i-1];
    }
    int i = 0, j = 1, mbooks = 0;
    while (i < pf.size() - 1 && j < pf.size()) {
        int sum = pf[j] - pf[i];
        if (sum <= t) {
            mbooks = max(mbooks, j - i);
            j++;
        } else i++;
    }
    return mbooks;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, t; cin >> n >> t;
    vector<int> arr;
    while (n--) {
        int x; cin >> x;
        arr.pb(x);
    }

    cout << solve(arr, t);
}