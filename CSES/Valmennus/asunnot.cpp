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

    int n, m, k; cin >> n >> m >> k;

    vector<int> wishes(n), sizes(m);
    for (int i = 0; i < n; i++) cin >> wishes[i];
    for (int i = 0; i < m; i++) cin >> sizes[i];
    sort(all(wishes));
    sort(all(sizes));

    int ans = 0, minvalid = 0;
    for (auto wish : wishes) {
        for (int i = minvalid; i < m; i++) {
            if (sizes[i] < wish - k) minvalid = i + 1;
            else if (sizes[i] > wish + k) break;
            else {
                ans++;
                minvalid = i + 1;
                break;
            }
        }
    }
    cout << ans;
}