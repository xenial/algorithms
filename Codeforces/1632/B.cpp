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

        int p = 1;
        while ((p << 1) <= N - 1) p <<= 1;
        for (int i = N - 1; i >= p; i--)
            cout << i << " ";
        
        for (int i = 0; i < p; i++)
            cout << i << " ";
        
        cout << endl;
    }
}
