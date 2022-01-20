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
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

#define mx 200005

int N;
ll dp[mx];

struct project {
    int a, b;
    ll p;
};

vector<project> pjs;

bool cmp(project &v1, project &v2) {
    return v1.b < v2.b;
}

int main() {
	set_io("");

    cin >> N;

    pjs.rsz(N);
    for (auto &p : pjs) cin >> p.a >> p.b >> p.p;
    sort(all(pjs), cmp);

    dp[0] = pjs[0].p;
    for (int i = 1; i < N; i++) {
        project cur = pjs[i];
        
        ll l = -1, r = i;
        while (l + 1 < r) {
            ll m = (l + r) / 2;

            if (pjs[m].b >= cur.a) r = m;
            else l = m;
        }

        if (l == -1) dp[i] = max(dp[i - 1], cur.p);
        else dp[i] = max(dp[i - 1], dp[l] + cur.p);
    }

    cout << dp[N - 1] << endl;
}
