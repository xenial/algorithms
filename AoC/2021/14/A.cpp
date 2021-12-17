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

string s;
map<string, char> op;

void tick() {
    for (int r = 1; r < s.sz(); r++) {
        string sub = string(s.begin() + r - 1, s.begin() + r + 1);
        if (!op[sub]) continue;

        s.insert(s.begin() + r, op[sub]);
        r++;
    }
}

int main() {
	set_io("");

    cin >> s;
    for (int i = 0; i < 100; i++) {
        string k; cin >> k;
        char c; cin >> c;
        op[k] = c;
    }

    for (int i = 0; i < 10; i++) tick();

    vector<int> counts(26);
    for (auto c : s) counts[c - 'A']++;
    sort(all(counts));
    int l;
    for (auto n : counts)
        if (n) {
            l = n;
            break;
        }
    cout << *(counts.end() - 1) - l << '\n';
}
