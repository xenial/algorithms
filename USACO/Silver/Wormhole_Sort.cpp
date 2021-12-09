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

int find(int n) {
    if (n != parent[n]) parent[n] = find(parent[n]);
    return parent[n];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (height[a] < height[b]) swap(a, b);

    height[a] = height[a] == height[b] ? height[a] + 1 : height[a];
    parent[b] = a;
}

struct wh {
    int a, b, w;
};

bool cmp(wh a, wh b) {
    return a.w > b.w;
}

int cows[100005];
vector<wh> whs;
int main() {
    set_io("wormsort");

    int N, M; cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> cows[i];
        parent[i] = i;
        height[i] = 1;
    }
    for (int i = 0; i < M; i++) {
        wh h;
        cin >> h.a >> h.b >> h.w;
        whs.pb(h);
    }
    bool sortable = true;
    for (int i = 1; i <= N; i++) if (find(i) != find(cows[i])) sortable = false;
    if (sortable) {
        cout << -1 << endl;
        return 0;
    }

    sort(all(whs), cmp);

    int ans, i = 1;
    for (auto h : whs) {
        ans = h.w;
        unite(h.a, h.b);
        while (find(i) == find(cows[i]) && i <= N) i++;
        if (i >= N) break;
    }
    cout << ans << endl;
}
