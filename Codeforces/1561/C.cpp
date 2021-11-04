#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int min_cave(vector<int> cave) {
    int min = cave[0] + 1;
    vector<int> scave = cave;
    sort(all(scave));

    for (int i = scave.size(); i >= 0; --i) {
        int m_id = find(all(cave), scave[i]) - cave.begin();
        min = max(scave[i] + 1 - i, min);
    }
    return min;
}

int solve(vector<vector<int>> caves) {
    vector<pair<int,int>> mincaves;
    for (int i = 0; i < caves.size(); i++) {
        pair<int,int> mcave;
        mcave.first = min_cave(caves[i]);
        mcave.second = caves[i].size();
        mincaves.push_back(mcave);
    }
    sort(all(mincaves));
    int minpwr = INT_MAX;
    for (int i = mincaves.size() - 1; i >= 0; --i) {
        int total = mincaves[i].first + mincaves[i].second;
        if (total >= mincaves[i + 1].first) {
            mincaves[i].second = 0;
        } else {
            mincaves[i].first = mincaves[i].first + mincaves[i + 1].first - total + 1;
            mincaves[i].second = 0;
        }
        minpwr = min(mincaves[i].first, minpwr);
    }
    return minpwr;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        vector<vector<int>> caves;
        int n; cin >> n;
        while (n--) {
            vector<int> cave;
            int mc; cin >> mc;
            while (mc--) {
                int monster; cin >> monster;
                cave.push_back(monster);
            }
            caves.push_back(cave);
        }
        cout << solve(caves) << endl;
    }
}