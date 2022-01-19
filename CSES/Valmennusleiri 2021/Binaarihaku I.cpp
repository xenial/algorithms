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
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int N, Q;
vector<int> arr;

int main() {
	set_io("");

    cin >> N >> Q;

    arr.rsz(N);
    for (auto &n : arr) cin >> n;
    sort(all(arr));

    while (Q--) {
        int x; cin >> x;
        if (x == *lower_bound(all(arr), x)) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
}
