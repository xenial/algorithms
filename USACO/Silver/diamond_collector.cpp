#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

bool cmp(pair<int,int> v1, pair<int,int> v2) {
    return v1.se - v1.fi < v2.se - v2.fi;
}

int diff(pair<int,int> x) {
    return x.se - x.fi;
}

int solve(vector<int> arr, int x) {
    sort(all(arr));
    vector<int> lens(arr.size());
    int i = 0, j = 1;
    while (i <= j) {
        if (i == lens.size()) break;
        int diff = arr[j] - arr[i];
        if (diff <= x && j < lens.size()) j++;
        else if (diff > x || j == lens.size()) {
            lens[i] = j - i;
            i++;
        }
    }
    vector<int> max_noverlap(lens.size());
    for (int i = lens.size() - 1; i >= 0; --i) {
        if (i + lens[i] >= lens.size()) max_noverlap[i] = 0;
        else max_noverlap[i] = max(max_noverlap[i+1], lens[i + lens[i]]);
    }

    int r = 0;
    for (int i = 0; i < lens.size(); i++) {
        r = max(r, lens[i] + max_noverlap[i]);
    }
    return r;
}

int main() {
    set_io("diamond");

    int n, k; cin >> n >> k;
    vector<int> arr;
    while (n--) {
        int x; cin >> x;
        arr.pb(x);
    }
    cout << solve(arr, k);
}