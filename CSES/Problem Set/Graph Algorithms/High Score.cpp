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

struct edge {
    ll w;
    int n;
};
 
int N, M;
vector<vector<edge>> adj;
bool vis[2505];
ll score[2505];
 
int main() {
	set_io("");
 
    cin >> N >> M;
    adj.rsz(N + 1);
 
    for (int i = 0; i < M; i++) {
        int a, b, x; cin >> a >> b >> x;
        adj[a].pb({x, b});
    }

    fill_n(score, 2505, -1e18);
    score[1] = 0;

    bool cycles = true;
    for (int i = 0; i < N; i++) {
        bool improved = false;
        for (int n = 1; n <= N; n++) {
            if (score[n] == -1e18) continue;
            for (auto e : adj[n]) {
                if (score[n] + e.w > score[e.n]) {
                    improved = true;
                    score[e.n] = score[n] + e.w;
                }
            }
        }
        if (!improved) {
            cycles = false;
            break;
        }
    }

    if (!cycles) {
        cout << score[N] << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        bool improved = false;
        for (int n = 1; n <= N; n++) {
            if (score[n] == -1e18) continue;
            for (auto e : adj[n]) {
                if (score[n] + e.w > score[e.n]) {
                    improved = true;
                    score[e.n] = 1e18;
                }
            }

        }
        if (!improved) break;
    }

    cout << (score[N] == 1e18 ? -1 : score[N]) << endl;
}