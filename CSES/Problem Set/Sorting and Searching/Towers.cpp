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

int solve(vector<int> cubes) {
    multiset<int> towers;

    for (auto cube : cubes) {
        if (!towers.sz()) towers.insert(cube);
        else if (cube >= *(--towers.end())) towers.insert(cube);
        else {
            towers.erase(towers.find(*towers.upper_bound(cube)));
            towers.insert(cube);
        }
    }

    return towers.sz();
}

int main() {
    set_io("");

    int n; cin >> n;
    vector<int> cubes;
    
    while (n--) {
        int k; cin >> k;
        cubes.pb(k);
    }
    cout << solve(cubes);
}