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

    int x, n; cin >> x >> n;

    set<pair<int, int>> parts;
    multiset<int> lengths;
    parts.insert({0, x});
    lengths.insert(x);

    int ans = 0;
    while (n--) {
        int k; cin >> k;
        auto it = parts.upper_bound({-k, 0});
        pair<int,int> s1({(*it).fi, k - abs((*it).fi)}), s2({s1.fi - s1.se, (*it).se - s1.se});

        lengths.insert(s1.se);
        lengths.insert(s2.se);
        lengths.erase(lengths.find((*it).se));

        cout << *(--lengths.end()) << " ";

        parts.insert(s1); 
        parts.insert(s2);
        parts.erase(it);
    }
}