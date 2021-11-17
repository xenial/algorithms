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

int height[300005], parent[300005], info[3][300005];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    if (height[a] < height[b]) swap(a, b);

    int ra = find(a), rb = find(b);
    if (ra == rb) return;

    parent[rb] = ra;
    height[ra] = max(height[ra], height[rb] + 1);
    info[0][ra] = max(info[0][ra], info[0][rb]);
    info[1][ra] = min(info[1][ra], info[1][rb]);
    info[2][ra] += info[2][rb];
}

int main() {
    set_io("");

    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        info[0][i] = info[1][i] = i;
        info[2][i] = 1;
    }

    while (M--) {
        string op; cin >> op;
        
        if (op == "union") {
            int a, b; cin >> a >> b;
            unite(a, b);
        } else {
            int n; cin >> n;
            int r = find(n);
            cout << info[1][r] << " " << info[0][r] << " " << info[2][r] << endl;
        }
    }
}
