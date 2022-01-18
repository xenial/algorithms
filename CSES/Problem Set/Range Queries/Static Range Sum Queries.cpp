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
ll pfx[200005];

int main() {
	set_io("");

    cin >> N >> Q;

    cin >> pfx[1];
    for (int i = 2; i <= N; i++) {
        cin >> pfx[i];
        pfx[i] += pfx[i - 1];
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        cout << pfx[b] - pfx[a - 1] << endl;
    }
}
