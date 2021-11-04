#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> a, int pts) {
    if (a.size() == 1)
        return a[0] + pts;
    if (a.size() == 0)
        return 0 + pts;

    map<int, int> counts;
    vector<int> sa = a;
    sort(sa.begin(), sa.end());

    counts.insert(make_pair(sa[0], 1));
    for (int i = 1; i < sa.size(); i++) {
        if (sa[i] == sa[i - 1])
            counts.find(sa[i])->second++;
        else
            counts.insert(make_pair(sa[i], 1));
    }

    map<int, int>::iterator cf = counts.find(a[0]);
    pair<int, int> bpg {0, cf->first * cf->second};
    for (int i = 1; i < a.size() - 1; i++) {
        map<int, int>::iterator c1, c2, c3, cbi;
        c1 = counts.find(a[i - 1]); c2 = counts.find(a[i]); c3 = counts.find(a[i + 1]);
        ll pg = c2->first * c2->second - c1->first * c1->second - c3->first * c3->second;

        if (i == a.size() - 2)
            pg = c3->first * c3->second - c2->first * c2->second;

        if (bpg.second < pg) {
            bpg.first = i;
            bpg.second = pg;
        }
    }
    int b = a[bpg.first];

    if (bpg.first == 0) {
        vector<int>::iterator rm;
        do {
            rm = find(a.begin(), a.end(), a[bpg.first + 1]);
            a.erase(rm);
        } while (rm != a.end());
    } else if (bpg.first == a.size() - 2) {
        vector<int>::iterator rm;
        do {
            rm = find(a.begin(), a.end(), a[bpg.first - 1]);
            a.erase(rm);
        } while (rm != a.end());
    } else {
        vector<int>::iterator rm;
        do {
            rm = find(a.begin(), a.end(), a[bpg.first - 1]);
            a.erase(rm);
        } while (rm != a.end());

        do {
            rm = find(a.begin(), a.end(), a[bpg.first + 1]);
            a.erase(rm);
        } while (rm != a.end());
    }

    return solve(a, b) + pts;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t, n; cin >> t;
    vector<int> a;
    while (t--) {
        cin >> n;
        a.push_back(n);
    }
    cout << solve(a, 0);
}