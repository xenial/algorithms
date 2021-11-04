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

string solve(vector<int> arr) {
    string ans;
    for (auto n : arr) {
        ans += (char)96 + n;
    }
    return ans;
}

int main() {
    set_io("");

    vector<int> arr(26);
    for (int i = 0; i < 26; i++) {
        cin >> arr[i];
    }

    cout << solve(arr);
}