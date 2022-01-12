#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int,int>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int main() {
	set_io("");

    int n; cin >> n;

    vector<int> arr(n), dp(n + 5, 1e9);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 1;
    dp[0] = -1e9;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(all(dp), arr[i]) - dp.begin();
        if (arr[i] > dp[j - 1] && arr[i] < dp[j]) dp[j] = arr[i];
    }

    int l = 0, r = n + 1;

    while (l + 1 < r) {
        int m = (l + r) / 2;

        if (dp[m] == 1e9) r = m;
        else l = m;
    }

    cout << l << endl;
}
