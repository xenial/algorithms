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

int parent[100005], height[100005];

int find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    if (height[a] < height[b]) swap(a, b);

    int ra = find(a), rb = find(b);
    parent[rb] = ra;
    height[ra] = max(height[ra], height[rb] + 1);
}

int main() {
    set_io("");

    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) parent[i] = i;

    while (M--) {
        string op; cin >> op;
        int a, b; cin >> a >> b;

        if (op == "union") unite(a, b);
        else cout << (find(a) == find(b) ? "YES" : "NO") << endl;
    }
}
