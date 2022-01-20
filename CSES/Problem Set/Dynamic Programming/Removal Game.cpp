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

int N;
ll dp[5005][5005][2];

int main() {
	set_io("");

    cin >> N;

    vector<ll> nums(N);
    for (auto &n : nums) cin >> n;

    for (int i = 0; i < N; i++) {
        dp[i][i][0] = nums[i];
        dp[i][i][1] = 0;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j + i < N; j++) {
            ll l = nums[j] + dp[j + 1][j + i][1],
            r = nums[j + i] + dp[j][j + i - 1][1];
            
            if (l > r) {
                dp[j][j + i][0] = l;

                if (i != 1) {
                    dp[j][j + i][1] =
                        max(nums[j + 1] + dp[j + 2][j + i][1],
                            nums[j + i] + dp[j + 1][j + i - 1][1]);
                } else dp[j][j + i][1] = nums[j + 1];
            } else {
                dp[j][j + i][0] = r;

                if (i != 1) {
                    dp[j][j + i][1] =
                        max(nums[j] + dp[j + 1][j + i - 1][1],
                            nums[j + i - 1] + dp[j][j + i - 2][1]);
                } else dp[j][j + i][1] = nums[j];
            }
        }
    }

    cout << dp[0][N - 1][0] << endl;
}
