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
ll Min[200005][20];

int main() {
	set_io("");

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        Min[i][0] = n;
    }

    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        int l = b - a + 1, e = (int)log2(l);
        cout << min(Min[a][e], Min[b - (1 << e) + 1][e]) << endl;
    }
}
