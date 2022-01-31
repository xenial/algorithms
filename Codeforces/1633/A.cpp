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

        if (N % 7 == 0) {
            cout << N << endl;
            continue;
        }

        string s = to_string(N);
        for (auto &c : s) {
            char o = c;
            for (int i = 1; i <= 9; i++) {
                c = '0' + i;
                if (stoi(s) % 7 == 0) {
                    cout << s << endl;
                    break;
                }
            }
            if (stoi(s) % 7 == 0) break;
            else c = o;
        }
    }
}
