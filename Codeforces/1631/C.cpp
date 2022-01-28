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
        int N, K; cin >> N >> K;

        if (K == 0) {
            for (int i = N - 1; i >= N / 2; i--) {
                int c = i ^ (N - 1);
                cout << i << " " << c << endl;
            }
        } else if (K < N - 1) {
            int kc = K ^ (N - 1);
            for (int i = N - 2; i >= N / 2; i--) {
                int c = i ^ (N - 1);
                if (i == kc || i == K || c == K) continue;
                cout << i << " " << c << endl;
            }
            cout << 0 << " " << kc << endl;
            cout << K << " " << N - 1 << endl;
        } else if (K == N - 1) {
            if (N == 4) {
                cout << -1 << endl;
                continue;
            }

            cout << N - 1 << " " << N - 2 << endl;
            cout << N - 3 << " " << 1 << endl;
            cout << 2 << " " << 0 << endl;

            for (int i = N - 4; i >= N / 2; i--) {
                int c = i ^ (N - 1);
                cout << i << " " << c << endl;
            }
        }
    }
}
