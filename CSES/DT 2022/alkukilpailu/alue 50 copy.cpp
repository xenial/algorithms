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

int ans[50][50] = {0};
vector<vector<int>> paths(100, vector<int>(100)), spaths(100, vector<int>(100));
vector<pair<int,int>> uniques;

int main() {
    set_io("C:/Users/maste/OneDrive/Programming/learning/alue50");

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cin >> paths[i][j];
        }
    }
    spaths = paths;

    for (int i = 0; i < 100; i++) sort(all(spaths[i]));

    for (int i = 0; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            vector<int> temp;
            set_intersection(all(spaths[i]), all(spaths[j]), back_inserter(temp));
            if (temp.empty()) uniques.pb({i, j});
        }
    }

    for (int i = 0; i < 50; i++) {}
}