#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

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
    string ans = "a";

    for (int i = 1; i < n; i++) {
        int temp = ans.sz() * 2;
        for (int j = 0; j <= temp; j += 2) {
            ans.insert(ans.begin() + j, 'a' + i);
        }
    }

    cout << ans;
}