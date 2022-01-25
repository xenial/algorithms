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

int N;

int main() {
	set_io("");

    cin >> N;

    set<int> c;

    for (int i = 1; i <= N; i++) c.insert(i);

    auto it = c.begin();
    while (c.sz() > 1) {
        auto n = c.upper_bound(*it);
        if (n == c.end()) n = c.begin();
        cout << *n << " ";
        it = c.upper_bound(*n);
        if (it == c.end()) it = c.begin();
        c.erase(n);
    }
    cout << *c.begin() << endl;
}
