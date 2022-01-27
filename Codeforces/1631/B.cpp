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

int main() {
	set_io("");

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        
        vi a(N);
        for (auto &i : a) cin >> i;

        int tn = a[N - 1], tnc = 1;
        for (int i = 0; i < N - 1; i++)
            if (a[i] == tn) tnc++;

        if (tnc == N) {
            cout << 0 << endl;
            continue;
        }

        int cc = 0, ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (a[i] == tn) cc++;
            else {
                int ni = i;
                for (int j = 0; j < cc; j++) {
                    if (i - j >= 0) {
                        ni = i - j;
                        if (a[i - j] != tn) tnc++;
                    }
                }
                ans++;
                i = ni;
                cc *= 2;
                if (tnc >= N) {
                    cout << ans << endl;
                    continue;
                }
            }
        }
    }
}
