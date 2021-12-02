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

    deque<int> q;
    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        q.pb(x);
    }
    int prev = accumulate(all(q), 0), ans = 0;

    for (int i = 3; i < 2000; i++) {
        int x; cin >> x;
        int cur = prev - q.front() + x;

        if (cur > prev) ans++;

        q.pop_front();
        q.pb(x);
        prev = cur;
    }

    cout << ans << endl;
}
