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

int T;

int main() {
	set_io("");

    cin >> T;

    while (T--) {
        int N; cin >> N;

        vi a(N), b(N);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        for (int i = 0; i < N; i++)
            if (a[i] > b[i]) swap(a[i], b[i]);

        cout << *(max_element(all(a))) * *(max_element(all(b))) << endl;
    }
}
