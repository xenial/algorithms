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

int main() {
    set_io("");

    vector<int> nums;
    int n, k; cin >> n >> k;

    while (n--) {
        int x; cin >> x;
        nums.pb(x);
    }

    while (k--) {
        int x; cin >> x;
        int l = -1, r = nums.sz();

        while (r > l + 1) {
            int m = (l + r) / 2;

            if (nums[m] > x) r = m;
            else l = m;
        }

        cout << l + 1 << endl;
    }
}