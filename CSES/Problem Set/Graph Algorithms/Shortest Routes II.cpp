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

ll sp[510][510];

int main() {
    set_io("");

    fill_n(&sp[0][0], 510*510, 1e18);

    int N, M, Q; cin >> N >> M >> Q;

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        sp[a][b] = sp[b][a] = min(sp[a][b], (ll)c);
        sp[a][a] = sp[b][b] = 0;
    }

    for (int i = 1; i <= N; i++)
        for (int a = 1; a <= N; a++) 
            for (int b = 1; b <= N; b++) 
                sp[a][b] = sp[b][a] = min(sp[a][b], sp[a][i] + sp[b][i]);

    while (Q--) {
        int a, b; cin >> a >> b;
        cout << (sp[a][b] == 1e18 ? -1 : sp[a][b]) << endl;
    }
}
