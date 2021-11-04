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

    int n, m; cin >> n >> m;

    vector<int> arrivals(m), arrivals_s;
    for (int i = 0; i < m; i++) cin >> arrivals[i];
    arrivals_s = arrivals;
    sort(all(arrivals_s));

    int row = 0, last = 0;
    for (auto arrival : arrivals_s) {
        if (arrival - last == 1) {
            row++;
            last = arrival;
        } else break;
    }

    set<int> ans;
    for (int i = 1; i <= row + 1; i++) ans.insert(i);
    for (auto arrival : arrivals) {
        ans.erase(arrival);
        cout << *ans.begin() << " ";
    }
}