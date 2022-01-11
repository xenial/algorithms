#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

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
    set<int> lights; lights.insert(0); lights.insert(x);
    multiset<int> gaps;
    while (n--) {
        int y; cin >> y;
        lights.insert(y);
        auto it = lights.upper_bound(y);
        auto it2 = lights.lower_bound(y); --it2;
        auto it3 = gaps.find(*it - *it2);
        if (it3 != gaps.end()) gaps.erase(gaps.find(*it - *it2));
        gaps.insert(y - *it2); gaps.insert(*it - y);
        cout << *(--gaps.end()) << " ";
    }
}